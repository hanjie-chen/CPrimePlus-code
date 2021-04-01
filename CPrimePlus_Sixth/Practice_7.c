#include "stdio.h"
#include "string.h"
#define SIZE 26
int main(void)
{
    char letter[SIZE];

    printf("请输入一个任意的单词：");
    scanf("%s", letter);
    for (int i = strlen(letter) - 1; i >= 0; --i) {
        printf("%c", letter[i]);
    }printf("\n");
    return 0;
}