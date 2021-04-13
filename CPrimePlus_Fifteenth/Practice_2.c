#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE CHAR_BIT * sizeof(int) 

int binary_to_int(const char *);
char * integer_to_binary_string(int, char *); // 把一个整数显示为一个二进制字符串
void show_binary_string(const char *); // 显示字符串

int main(int argc,char * argv[])
{
    int first, second;
    int result;
    char binary_string[SIZE];

    if (argc != 3)
    {
        printf("Please enter 2 string which is the 8 bits binary string\n");
        exit(EXIT_FAILURE);
    }
//    首先让其变为整数
    first = binary_to_int(argv[1]);
    second = binary_to_int(argv[2]);
//    两个整数取反
    result = ~first;
    show_binary_string(integer_to_binary_string(result, binary_string));
    result = ~second;
    show_binary_string(integer_to_binary_string(result, binary_string));
//    两个整数&
    result = first & second;
    show_binary_string(integer_to_binary_string(result, binary_string));
//    两个整数|
    result = first | second;
    show_binary_string(integer_to_binary_string(result, binary_string));
//    两个整数^
    result = first ^ second;
    show_binary_string(integer_to_binary_string(result, binary_string));

    return 0;
}
int binary_to_int(const char * string)
{
    int result = 0;

//    判断符号位
    if (*string == '0') // 如果大于0
    {
//        让字符串从符号位一到下一位
        string++;
        while (*string)
        {
            result |= (*string - '0'); // 让result一直赋值
            result <<= 1; // 让result左移一位
            string++; // 移动字符串
        }
//        多移动了一位
        result >>= 1;
    }
    else if (*string == '1') // 如果小于0
    {
        while (*string)
        {
            result |= (*string - '0'); // 让result一直赋值
            result <<= 1; // 让result左移一位
            string++; // 移动字符串
        }
//        多移动了一位
        result >>= 1;
        result = -((1 << 8) - result);
    }

    return result;
}
char * integer_to_binary_string(int number, char * ps)
{
    const static int size = CHAR_BIT * sizeof(int);

    for (int i = size - 1; i >= 0; --i, number >>= 1)
        ps[i] = (01 & number) + '0';
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
    }putchar('\n');
}
