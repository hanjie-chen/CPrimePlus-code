#include "stdio.h"
void Display(char ch, int lines, int width);
int main(void)
{
    int ch;
    int rows, cols;

    printf("Please enter a character and two integers:");
    while ((ch = getchar()) != '\n')
    {
        if (scanf("%d %d", &rows, &cols) != 2)
        {
            printf("Please follow the guide of tips\n");
            break;
        }
//        使用一个while循环来消耗缓冲区剩下的字符
        while (getchar() != '\n')
            continue;
        Display(ch, rows, cols);
        printf("Enter another character and two integers.\n");
        printf("Enter a newline to quit.\n");
    }
    printf("Bye~.\n");

    return 0;
}
void Display(char ch, int lines, int width)
{
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < width; ++j) {
            putchar(ch);
        }putchar('\n');
    }
}