#include <stdio.h>

#define STR_LEN 5

int main(void)
{
    char words[STR_LEN];

    puts("Enter a string, please");
//    出现warning的原因是 gets函数不检查数组是否有足够的空间装入输入的值
//    如果输入的字符串过长 会导致缓冲区溢出
//    如果数组后面只是未占用的地址 那么不会导致问题  如果它们擦写掉了程序的其他数据那么就有可能倒是程序异常终止或者其他问题
    gets(words);
    printf("Your string twice:\n");
    puts(words);
    printf("%s\n", words);
    printf("Done.\n");

    return 0;
}