#include "stdio.h"
#define SIZE 10
int main(void)
{
    int number_array[SIZE];

    for (int i = 0; i < 8; ++i) {
        scanf("%d", &number_array[i]);
    }
    for (int i = 7; i >= 0; --i) {
        printf("%d ", number_array[i]);
    }printf("\n");

    return 0;
}