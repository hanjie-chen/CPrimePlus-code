#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

struct font_format {
    unsigned char font_id   : 8; // 字体ID
    unsigned char font_size : 7; // 字体大小
    unsigned char           : 1; // 填充位
    unsigned char align     : 2; // 对齐 左对齐0 居中1 右对齐2
    unsigned char bold      : 1; // 加粗 1 开 0 关
    unsigned char italic    : 1; // 斜体 1 开 0 关
    unsigned char underline : 1; // 下划线 1开 0 关
};
const char * pt_off = "off";
const char * pt_on = "on";
const char * pt_left = "left";
const char * pt_middle = "center";
const char * pt_right = "right";
const int mask = -1;

#define SIZE CHAR_BIT * sizeof(int)

void Print_Font_Information(struct font_format * ps);
void Choose_Operation(char ch, struct font_format *);
void Change_Font_ID(struct font_format *);
void Change_Font_SIZE(struct font_format *);
void Change_Font_ALIGN(struct font_format *);
void Change_Font_BOID(struct font_format *);
void Change_Font_ITALIC(struct font_format *);
void Change_Font_UNERLINE(struct font_format *);
void Print_Menu(void);
char get_input(void);
char get_letter(void);
void eat_line(void);

int main(void)
{
//    注意 位字段初始化的时候并不会理会空缺部分 所以这个CLion的提示是错误的
    struct font_format microsoft_black = {1, 12, 0, 0, 0, 0};
    char choice;

    puts("Now the initialization microsoft black font format is the following:");
    Print_Font_Information(&microsoft_black);
    while (1)
    {
        Print_Menu();
        choice = get_input();
        if ('q' == choice)
            break;
        Choose_Operation(choice, &microsoft_black);
        Print_Font_Information(&microsoft_black);
    }
    puts("Bye~");

    return 0;
}
void Print_Font_Information(struct font_format * ps)
{
    const char * pc;

    if (ps->align == 0)
        pc = pt_left;
    else if (ps->align == 1)
        pc = pt_middle;
    else if (ps->align == 2)
        pc = pt_right;
    else
        pc = "unknown type";
    printf(" ID SIZE ALIGNMENT  B    I    U\n");
    printf("%3d%4d%10s%5s%5s%5s\n", ps->font_id, ps->font_size, pc,
            ps->bold ? pt_on : pt_off, ps->italic ? pt_on : pt_off, ps->underline ? pt_on : pt_off);
}
void Choose_Operation(char ch, struct font_format * ps)
{
    switch (ch) {
        case 'f':Change_Font_ID(ps); break;
        case 's':Change_Font_SIZE(ps); break;
        case 'a':Change_Font_ALIGN(ps);break;
        case 'b':Change_Font_BOID(ps); break;
        case 'i':Change_Font_ITALIC(ps); break;
        case 'u':Change_Font_UNERLINE(ps); break;
        default:puts("unknown choose");
            break;
    }
}
void Change_Font_ID(struct font_format * ps)
{
    int id;
    int local_mask;

    local_mask = mask >> (SIZE - 8);
    puts("Enter font id (0~255):");
    while (scanf("%d", &id) != 1)
    {
        eat_line();
        puts("Please enter a integer, please try again");
        puts("Enter font id (0~255):");
    }eat_line();
    ps->font_id = id & local_mask;
}
void Change_Font_SIZE(struct font_format * ps)
{
    int size;
    int local_mask;

    local_mask = mask >> (SIZE - 7);
    puts("Enter font size (0~127):");
    while (scanf("%d", &size) != 1)
    {
        eat_line();
        puts("Please enter a integer which between 0 and 127, please try again");
        puts("Enter font size (0~127):");
    }eat_line();
    ps->font_size = size & local_mask;
}
void Change_Font_ALIGN(struct font_format * ps)
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
        ps->align = 0;
    else if (ch == 'c')
        ps->align = 1;
    else if (ch == 'r')
        ps->align = 2;
    else
        puts("unknown alignment type");

}
void Change_Font_BOID(struct font_format * ps)
{
    if (ps->bold == 1)
        ps->bold = 0;
    else if (ps->bold == 0)
        ps->bold = 1;
}
void Change_Font_ITALIC(struct font_format * ps)
{
    if (ps->italic == 1)
        ps->italic = 0;
    else if (ps->italic == 0)
        ps->italic = 1;
}
void Change_Font_UNERLINE(struct font_format * ps)
{
    if (ps->underline == 1)
        ps->underline = 0;
    else if (ps->underline == 0)
        ps->underline = 1;
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