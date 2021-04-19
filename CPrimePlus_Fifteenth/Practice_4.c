#include <stdio.h>

int Judge_Bit(int , int );

int main(void)
{
    int number = 5;
    int location = 1;
//    注意这个位是从右边往左边的数过去的
    printf("The number %d and its %d location bit is %s", number, location, Judge_Bit(number, location) ? "open" : "close");

    return 0;
}
int Judge_Bit(int number, int location)
{
    int mask = 1;
    int result = -1;

    number >>= location - 1;
    if ((mask & number) == 1)
        result = 1;
    else if ((mask & number) == 0)
        result = 0;

    return result;
}