#include "stdio.h"
#define SIZE 26
int main(void)
{
    char string[SIZE];
    char i;
    int j;

    for (i = 'a', j = 0; i <= 'z'; ++i, ++j) {
        string[j] = i;
    }
    for (j = 0; j < 26; ++j) {
        printf("%c ", string[j]);
    }printf("\n");

    return 0;
}