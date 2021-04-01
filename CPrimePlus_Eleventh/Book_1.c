#include <stdio.h>

#define MSG "I am a symbolic string constant"
#define MAXLENGTH 81

int main(void)
{
    char word[MAXLENGTH] = "I am a string in an array";
    const char * pt1 = "Something is pointer at me";

    puts("Here are some stings:");
//    puts函数直接输出整个字符串 并且自动换行
    puts(MSG);
    puts(word);
    puts(pt1);
    word[8] = 'p';
    puts(word);

    return 0;
}