#include "stdio.h"
#include "ctype.h"
int main(void)
{
    char letter;

    printf("Please enter a letter to judge:");
    letter = getchar();
//    这种方式只适用于想ASCII码这样的字母是连续排列的编码方式
//    if (letter > 'a' && letter < 'z')
//        printf("Yes, it is lowercase\n");
//    这种方式使用所有的字符编码, 但是需要包含一个ctype.h的头文件
    if (islower(letter))
        printf("Yes, it is a lower case\n");

    return 0;
}