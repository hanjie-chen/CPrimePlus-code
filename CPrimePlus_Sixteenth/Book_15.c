#include <stdio.h>
#include <limits.h>
// c11新增特性 下面这个将无法通过编译 而assert()只是在程序运行时检查表达式
_Static_assert(CHAR_BIT == 16, "16-bit char falsely assumed");

int main(void)
{
    puts("char is 16 bits");
    return 0;
}