#include <stdio.h>

int main(void)
{
    char side_a[] = "Side A";
    char dont[] = {'W', 'O', 'W', '!'};
    char side_b[] = "Side B";
//    由于这个是编译器自动确定大小的数组 dont这个数组没有'\0'这个符号 puts函数会一直输出到遇到'\0'为止
//    所以puts函数必须有空字符才行
    puts(dont);

    return 0;
}