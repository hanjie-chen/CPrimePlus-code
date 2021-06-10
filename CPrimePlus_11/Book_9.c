#include <stdio.h>

#define STARS "***********************************"
#define STR_LEN 10

int main(void)
{
    char words[STR_LEN];
    int i;

    puts("Enter strings (empty line to quit):");
    while (fgets(words, STR_LEN, stdin) != NULL && words[0] != '\n')
    {
        i = 0;
        while ('\n' != words[i] && '\0' != words[i])
            ++i;
        if (words[i] == '\n')
            words[i] = '\0';
        else // 只要到达了字符数组的末尾 不匹配上\n就会自动执行下面的代码 去掉后面的输入 即最多输入10个字符
            while (getchar() != '\n')
                continue;
        puts(words);
    }
    puts("Done.");

    return 0;
}