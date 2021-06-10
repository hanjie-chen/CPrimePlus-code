#include <stdio.h>

#define SIZE 81

int main(void)
{
    char line[SIZE];
    /*
    // 这个条件相当于 gets(line) != NULL
    while (gets(line))
        puts(line);
    puts("Bye");
    */

    /*
    // 这个while和上面的程序同理
    while (fgets(line, SIZE, stdin))
        fputs(line, stdout);
    puts("Bye");
    */
    printf("需要注意的是puts()要和gets()配对使用 fputs()要和fgets()配对使用\n");
    printf("这样的话换行符的出现会比较合理");

    return 0;
}