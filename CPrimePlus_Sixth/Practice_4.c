#include "stdio.h"
int main(void)
{
    char j = 'A';
    int count;
    for (int i = 0; i < 6; ++i) {
        count = i;
        for ( ;count-- >= 0; ++j) {
            printf("%c ", j);
        }printf("\n");
    }
    return 0;
}