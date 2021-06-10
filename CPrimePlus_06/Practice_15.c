#include "stdio.h"
#include "string.h"
#define SIZE 256
int main(void)
{
    char string[SIZE];

    scanf("%s", string);
    for (int i = strlen(string) - 1; i >= 0; --i) {
        printf("%c", string[i]);
    }printf("\n");

    return 0;
}