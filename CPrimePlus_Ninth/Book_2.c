#include "stdio.h"
#include "string.h"
#define NAME "CHJ, INC."
#define ADDRESS "101 ZJ Plaza"
#define PLACES "ZJ, CA 94904"
#define SPACE ' '
#define WIDTH 40
//改进函数，更加的适用
void Show_N_Char(char ch, int count);

int main(void)
{
    int space;

//    第一行
    Show_N_Char('*', WIDTH);
    printf("\n");
//    第二行
    Show_N_Char(SPACE, 15);
    printf("%s\n", NAME);
//    第三行
    space = (WIDTH - strlen(ADDRESS)) / 2;
    Show_N_Char(SPACE, space);
    printf("%s\n", ADDRESS);
//    第四行
    Show_N_Char(SPACE, ((WIDTH - strlen(PLACES)) / 2));
    printf("%s\n", PLACES);
//    第五行
    Show_N_Char('*', WIDTH);
    printf("\n");

    return 0;
}
void Show_N_Char(char ch, int count)
{
    for (int i = 0; i <= count; ++i) {
        putchar(ch);
    }
}