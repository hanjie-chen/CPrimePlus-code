#include "stdio.h"
void pound(int n);
int main(void)
{
    int times = 5;
    char ch = '!';
    float f = 6.0;

    pound(times);
    pound(ch); //相当于(int)ch
    pound(f); //相当于(int)f
    return 0;
}
void pound(int n)
{
    while (n-- > 0)
    {
        printf("#");
    }printf("\n");
}