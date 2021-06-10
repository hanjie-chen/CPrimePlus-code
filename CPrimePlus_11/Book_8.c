#include <stdio.h>

#define STR_LEN 14
#define STARS "******************************************"

int main(void)
{
    char words[STR_LEN];

    printf("Please enter a string\n");
//    第一个参数是字符数组的地址 第二个参数是读取的最大长度 第三个参数是需要读入的文件 stdin表示读入键盘输入的数据
    fgets(words, STR_LEN, stdin);
    printf("Your string twice (fist is puts then is fputs)\n");
    puts(words);
//    第一个参数为字符串 第二个参数为需要写入的文件 stdout表示显示在计算机显示屏上面
    fputs(words, stdout);
    puts(STARS);
    puts("Enter another string please");
    fgets(words, STR_LEN, stdin);
    printf("Your string twice (first is puts then is fputs)\n");
    puts(words);
    fputs(words, stdout);
    printf("Done.");

    return 0;
}