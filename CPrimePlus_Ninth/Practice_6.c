#include <stdio.h>
#include <ctype.h>
int Judge_Character(char ch);
void Read_And_Tell(void); // 我不知道该起什么名字就先这样吧 这个函数的作用是读取一个字符并且返回这个字母在字母表中的位置
int main(void)
{

    printf("This program is give the location of your input letter in alphabet.\n");
    printf("Please use ^D to finish.\n");
    Read_And_Tell();
    printf("Bye~.\n");

    return 0;
}
int Judge_Character(char ch)
{
    int location;

    if (isalpha(ch))
    {
//        如果是小写字母返回字母-'a' 如果是大写字母-'A'
        if (islower(ch))
            location = ch - 'a' + 1;
        else
            location = ch - 'A' + 1;
    } else
        location = -1;

    return location;
}
void Read_And_Tell(void)
{
    char ch;
    int status;

    while ((ch = getchar()) != EOF)
    {
//        用于处理回车符号发送缓存区的字符时 自己不会被处理
        if (ch == '\n')
            continue;
        status = Judge_Character(ch);
        if (-1 == status)
            printf("Well %c is not a letter!.\n", ch);
        else
        {
            printf("Well %c is a letter!.\n", ch);
            printf("It location in alphabet is %d.\n", status);
        }
    }
}