#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char * read_word(void);

int main(void)
{
    unsigned int word_count;
    char * * pt_string;

    printf("How many words do you want to enter ? ");
    scanf("%u", &word_count);
    while (getchar() != '\n')
        continue;
//    创建一个指针数组用于存储每个单词
    pt_string = (char * *)malloc(word_count * sizeof(char *));
    printf("Enter %d words now :\n", word_count);
//    循环输入一句话
    for (int i = 0; i < word_count; ++i)
        pt_string[i] = read_word();
    puts("Here are your words: ");
    for (int i = 0; i < word_count; ++i)
        puts(pt_string[i]);
//    释放所有的内存 一个是指针数组的内存 一个由有函数中申请到的指向字符串的内存
    for (int i = 0; i < word_count; ++i)
        free(pt_string[i]);
    free(pt_string);

    return 0;
}
char * read_word(void)
{
    _Bool in_word = 0;
    char ch;
    char temp[20];
    int i = 0;
    char * result;

    while ((ch = getchar()) != '\n')
    {
        if (isalpha(ch))
        {
            temp[i] = ch;
            ++i;
            in_word = 1;
        }
        if (!isalpha(ch) && in_word == 1)
            break;
    }
//    分配内存
    result = (char *)malloc((i + 1) * sizeof(char));
//    把临时数组中的数据拷贝入malloc()分配的内存中去 并且使其成为一个字符串
    strncpy(result, temp, i);
    result[i] = '\0';

    return result;
}