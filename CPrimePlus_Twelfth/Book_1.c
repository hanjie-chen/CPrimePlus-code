#include <stdio.h>

// 关键字static知识表明其链接类型
int giants = 5; // 外部链接的文件作用域也称程序作用域 可用于所有的翻译单元
static int dodgers = 3;  // 内部链接的文件作用域 只能用于一个翻译单元

int main(void)
{
    auto int number;

    printf("Chj is trying to understand storage class\n");
    return 0;
}