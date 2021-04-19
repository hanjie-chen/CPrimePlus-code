#include <stdio.h>
#include <limits.h>

#define LEN CHAR_BIT * sizeof(int)

int rotate_left(unsigned int, int);
char * integer_to_binary_string(int, char *); // 把一个整数显示为一个二进制字符串
void show_binary_string(const char *); // 显示字符串

int main(void)
{
    unsigned int number = 999999999;
    int translate_bit = 4;
    char Binary[LEN + 1];

    printf("The binary of %d is:\n", number);
    show_binary_string(integer_to_binary_string(number, Binary));
    printf("After the translate the %d bit translate, the binary is:\n", translate_bit);
    show_binary_string(integer_to_binary_string(rotate_left(number, translate_bit), Binary));


    return 0;
}
int rotate_left(unsigned int number, int bits_count)
{
    int mask = -1; // 转换为二进制的话是全1位
    int temp;

//    确定掩码 掩盖的只剩下会被挤掉的bits_count位
    mask <<= LEN - bits_count;

//    收集number会被挤掉的bits_count位
    temp = number & mask;
//    右移使之回到需要被填充的位置
    temp >>= LEN - bits_count;

//    number左移bits_count位
    number <<= bits_count;
//    使用temp填充number
    number |= temp;

    return number;
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
    }
    putchar('\n');
}