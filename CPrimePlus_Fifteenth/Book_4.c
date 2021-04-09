#include <stdio.h>
#include <limits.h>

char * integer_to_binary_string(int, char *); // 把一个整数显示为一个二进制字符串
void show_binary_string(const char *); // 显示字符串
int invert_end(int, int );

int main(void)
{
    char binary_string[CHAR_BIT * sizeof(int) + 1]; // 最后一个位给 '\0'
    int number;

    puts("Enter the integer and see them in binary");
    puts("Non-numeric input terminates program");
    while (scanf("%d", &number) == 1)
    {
        integer_to_binary_string(number, binary_string);
        printf("%d is ", number);
        show_binary_string(binary_string);
        putchar('\n');
//        后四位取反
        number = invert_end(number, 4);
        printf("Inverting the last 4 bits gives\n");
        show_binary_string(integer_to_binary_string(number, binary_string)); // 联合使用两个函数
        putchar('\n');
    }
    puts("Bye~");

    return 0;
}
char * integer_to_binary_string(int n, char * ps)
{
    const static int size = CHAR_BIT * sizeof(int);

    for (int i = size - 1; i >= 0; --i, n >>= 1)
        ps[i] = (01 & n) + '0';
    ps[size] = '\0';

    return ps;
}
void show_binary_string(const char * string)
{
    int i = 0;

    while (string[i])
    {
        putchar(string[i++]);
        if (i % 4 == 0 && string[i])
            putchar(' ');
    }
}
int invert_end(int number, int bits)
{
    int mask = 0;
    int bit_val = 1;

    while(bits-- > 0)
    {
        mask |= bit_val;
        bit_val <<= 1;
    }

    return mask ^ number;
}