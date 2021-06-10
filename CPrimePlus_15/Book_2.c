#include <stdio.h>

int main(void)
{
    unsigned char source_number = 2;
    unsigned char result_number;

//    左移运算符 把二进制值左移n位 溢出的位丢失 空余的位使用0填充
    result_number = source_number << 2;
    printf("source number is %d and the result number is %d.\n", source_number,result_number);
//    右移运算符同理 只不过方面相反 （对于无符号数用0填充 对于有符号数结果取决于机器）
    result_number = source_number >> 1;
    printf("source number is %d and the result number is %d.\n", source_number,result_number);

    return 0;
}