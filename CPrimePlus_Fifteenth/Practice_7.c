#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

/* *
 * 以下是一个int位
0000 0000 最后三位分别为 B I U
0000 0000 最后两位 align
0000 0000 font size
0000 0000 font id
 * */
const char * pt_off = "off";
const char * pt_on = "on";
const char * pt_left = "left";
const char * pt_middle = "center";
const char * pt_right = "right";
/* 特别注意这个掩码mask
 * 这个掩码的右移值如果是有符号类型的话 在不同的系统中有的会使用1填充 有的会使用0填充
 * 故写出来的代码在不同的系统中运行可以会出问题
 * 在本系统中 macos 有符号的int右移是使用1填充的 故昨天写的代码出问题了
 * 但是使用unsigned int 类型的话右移在所有的系统中都会使用0填充
 * 所以这里使用unsigned int 类型
 * 陈翰杰 2021/4/19
 * */
const unsigned int mask = 4294967295; // 11111111 11111111 11111111 11111111
const int mask_id = 255; // 00000000 00000000 00000000 11111111
const int mask_size = 32512; // 00000000 00000000 01111111 00000000
const int mask_bold = 16777216; // 00000001 00000000 00000000 00000000
const int mask_italic = 16777216 * 2; // 00000010 00000000 00000000 00000000
const int mask_underline = 16777216 * 4; // 00000100 00000000 00000000 00000000
const int mask_align = -16711681; // 11111111 00000000 11111111 11111111

#define SIZE CHAR_BIT * sizeof(int)

void Print_Font_Information(unsigned int);
void Choose_Operation(char ch, unsigned int *);
void Change_Font_ID(unsigned int *);
void Change_Font_SIZE(unsigned int *);
void Change_Font_ALIGN(unsigned int *);
void Change_Font_BOID(unsigned int *);
void Change_Font_ITALIC(unsigned int *);
void Change_Font_UNERLINE(unsigned int *);
void Print_Menu(void);
char get_input(void);
char get_letter(void);
void eat_line(void);

int main(void)
{
    unsigned int microsoft_black = 0;
    char choice;


    puts("Now the initialization microsoft black font format is the following:");
    Print_Font_Information(microsoft_black);
    while (1)
    {
        Print_Menu();
        choice = get_input();
        if ('q' == choice)
            break;
        Choose_Operation(choice, &microsoft_black);
        Print_Font_Information(microsoft_black);
    }
    puts("Bye~");

    return 0;
}
void Print_Font_Information(unsigned int font_name)
{
    unsigned int find_align;
    const char * pc;

    find_align = font_name << 8;
    find_align >>= 24;

    if (find_align == 0)
        pc = pt_left;
    else if (find_align == 1)
        pc = pt_middle;
    else if (find_align == 2)
        pc = pt_right;
    else
        pc = "unknown type";
    printf(" ID SIZE ALIGNMENT  B    I    U\n");
    printf("%3d%4d%10s%5s%5s%5s\n", (font_name & mask_id), ((font_name & mask_size) >> 8), pc,
           ((font_name & mask_bold) >> 24) ? pt_on : pt_off, ((font_name & mask_italic) >> 25) ? pt_on : pt_off,
           ((font_name & mask_underline) >> 26) ? pt_on : pt_off);
}
void Choose_Operation(char ch, unsigned int * font_name)
{
    switch (ch) {
        case 'f':Change_Font_ID(font_name); break;
        case 's':Change_Font_SIZE(font_name); break;
        case 'a':Change_Font_ALIGN(font_name);break;
        case 'b':Change_Font_BOID(font_name); break;
        case 'i':Change_Font_ITALIC(font_name); break;
        case 'u':Change_Font_UNERLINE(font_name); break;
        default:puts("unknown choose");
            break;
    }
}
void Change_Font_ID(unsigned int * font_name)
{
    int id;
    int mask_get_number = mask >> 24; // 00000000 00000000 00000000 11111111
    int mask_operate_number = mask << 8; // 11111111 11111111 11111111 00000000

    puts("Enter font id (0~255):");
    while (scanf("%d", &id) != 1)
    {
        eat_line();
        puts("Please enter a integer, please try again");
        puts("Enter font id (0~255):");
    }eat_line();
//    首先把font_name的id位全部置0 其他位保持不变
    *font_name &= mask_operate_number;
//    然后将id限制在0~255范围之内 font_name将其或即可
    *font_name |= id & mask_get_number;
}
void Change_Font_SIZE(unsigned int * font_name)
{
    int size;
    int mask_get_number = mask >> 25;               // 00000000 00000000 00000000 01111111
    int mask_operate_number = ((mask << 16) | 255); // 11111111 11111111 00000000 11111111

    puts("Enter font size (0~127):");
    while (scanf("%d", &size) != 1)
    {
        eat_line();
        puts("Please enter a integer which between 0 and 127, please try again");
        puts("Enter font size (0~127):");
    }eat_line();
//    首先把size位全部置0
    *font_name &= mask_operate_number;
//    然后让size限制在范围之内 将其变为可以操作的数 让font_name将其或即可
    *font_name |= (size & mask_get_number) << 8;
}
void Change_Font_ALIGN(unsigned int * font_name)
{
    int ch;

    puts("Select alignment:");
    puts("l) left  c) center  r) right");
    ch = get_letter();
    eat_line();
    while (strchr("lcr", ch) == NULL)
    {
        puts("Please enter the 3 kind of letter l c and r, not other characters");
        puts("Please try again");
        ch = get_letter();
        eat_line();
    }
    if (ch == 'l')
        *font_name &= mask_align; // 保持其他位不变 align全部置0
    else if (ch == 'c')
        *font_name = (*font_name & mask_align) | (1 << 16); // 保持其他位不变 align位 置1
    else if (ch == 'r')
        *font_name = (*font_name & mask_align) | (1 << 17); // 保持其他位不变 align位 置2
    else
        puts("unknown alignment type");

}
void Change_Font_BOID(unsigned int * font_name)
{
    if (((*font_name & mask_bold) >> 24) == 1)
        *font_name &= ~mask_bold;
    else if (((*font_name & mask_bold) >> 24) == 0)
        *font_name |= mask_bold;
}
void Change_Font_ITALIC(unsigned int * font_name)
{
    if (((*font_name & mask_italic) >> 25) == 1)
        *font_name &= ~mask_italic;
    else if (((*font_name & mask_italic) >> 25) == 0)
        *font_name |= mask_italic;
}
void Change_Font_UNERLINE(unsigned int * font_name)
{
    if (((*font_name & mask_underline) >> 26) == 1)
        *font_name &= ~mask_underline;
    else if (((*font_name & mask_italic) >> 26) == 0)
        *font_name |= mask_underline;
}
void Print_Menu(void)
{
    puts("f) change font  s) change size    a) change alignment");
    puts("b) toggle bold  i) toggle italic  u) toggle underline");
    puts("q) quit");
}
char get_input(void)
{
    char ch;

    ch = get_letter();
    eat_line();
    while (strchr("fsabiuq", ch) == NULL)
    {
        puts("Please input the letters the menu provide");
        puts("Please try again");
        ch = get_letter();
        eat_line();
    }

    return ch;
}
char get_letter(void)
{
    char temp;

    while (1)
    {
        temp = tolower(getchar());
        if (isalpha(temp))
            break;
    }

    return temp;
}
void eat_line(void)
{
    while (getchar() != '\n')
        continue;
}