#include "stdio.h"
#include "ctype.h" //书中的P156有该头文件中的函数说明，用于某些特殊场合
int main(void)
{
    char ch;
//    getchar()/putchar()函数包含在stdio.h内，由于只处理字符，所以不用指定转换类型
    ch = getchar();
    while (ch != '\n')
    {
//        isalpha函数的参数是字母的时候，返回一个非0值,该函数在头文件ctype.h内部
        if (!isalpha(ch))
            putchar(ch);
        else
            putchar(ch+1);
        ch = getchar();
    }
    putchar(ch);
    return 0;
}