#include <stdio.h>

int main(void)
{
    unsigned char source_number = 2;
    unsigned char result_number;

//    二进制取反
    result_number = ~source_number;
    printf("source number is %d and result number is %d\n", source_number, result_number);
//    二进制按位与
    result_number = source_number & 3;
    printf("source number is %d and result number is %d\n", source_number, result_number);
//    二进制按位或
    result_number = source_number | 0377;
    printf("source number is %d and result number is %d\n", source_number, result_number);
//    二进制按位异或
    result_number = source_number ^ 0377;
    printf("source number is %d and result number is %d\n", source_number, result_number);

    return 0;
}