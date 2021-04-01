#include "stdio.h"
int main(void)
{
    char end_letter;

    printf("请输入结束字母（提示：大写字母）：");
    scanf("%c", &end_letter);
    for (int i = 0; i <= end_letter - 'A'; ++i) {
        for (int j = 0; j < end_letter - 'A' - i; ++j) {
            printf(" ");
        }
        for (char j = 'A'; j <= 'A' + i; ++j) {
            printf("%c", j);
        }
        for (int j = 'A' + i - 1; j >= 'A'; --j) {
            printf("%c", j);
        }
        printf("\n");
    }

    return 0;
}