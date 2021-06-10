#include <stdio.h>
void Char_Line(char ch, int col, int row);
int main(void)
{
    char ch;
    int row, col;

    printf("This program is print the characters your want.\n");
    printf("Now enter the character you want:");
    ch = getchar();
    printf("Now enter the row you want:");
    scanf("%d", &row);
    printf("Now enter the column you want:");
    scanf("%d", &col);
    Char_Line(ch, col, row);

    return 0;
}
void Char_Line(char ch, int col, int row)
{
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            putchar(ch);
        }putchar('\n');
    }
}