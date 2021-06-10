#include "stdio.h"
int main(void)
{
    for (char i = 'F'; i >= 'A'; --i) {
        for (char j = 'F'; j >= i; --j) {
            printf("%c", j);
        }
        printf("\n");
    }
    return 0;
}