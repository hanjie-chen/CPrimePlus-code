#include <stdio.h>

unsigned int count_me(void);

int main(void)
{
    unsigned int count;
    for (int i = 0; i < 10; ++i) {
        count = count_me();
    }
    printf("The for iteration %u times.\n", count);

    return 0;
}
unsigned int count_me(void)
{
    static unsigned int count_total = 0;

    count_total++;

    return count_total;
}