#include <stdio.h>
#include <limits.h>

#define SIZE CHAR_BIT * sizeof(int)

int Find_open_bit(int);

int main(void)
{
    printf("The number %d has open %d bits.\n", -1, Find_open_bit(-1));

    return 0;
}
int Find_open_bit(int number)
{
    int count = 0;
    int mask = 1;
//    使用掩码查看最后一位 让number的最后一位不停的右移
    for (int i = 0; i < SIZE ; ++i) {
        if ((number & mask) == 1)
            count++;
        number >>= 1;
    }

    return count;
}