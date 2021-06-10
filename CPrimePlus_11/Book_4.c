#include <stdio.h>

#define STARS "*********************************************"

int main(void)
{
//    初始化数组存储字符串 初始化指针指向字符串的区别
    char heart[] = "I love proton";
    const char * head = "I love NorthSea";

//    两者都可以使用数组表示法
    for(int i = 0; i < 6; ++i)
        putchar(heart[i]);
    putchar('\n');
    for(int i = 0; i < 6; ++i)
        putchar(head[i]);
    putchar('\n');
    puts(STARS);
//    都可以使用指针加法
    for (int i = 0; i < 6; ++i)
        putchar(*(heart + i));
    putchar('\n');
    for (int i = 0; i < 6; ++i)
        putchar(*(head + i));
    putchar('\n');
    puts(STARS);
//    只有指针可以使用递增操作
    while (*(head) != '\0')
        putchar(*(head ++));
    putchar('\n');
    puts(STARS);

    return 0;
}