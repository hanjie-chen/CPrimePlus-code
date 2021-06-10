#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

int main(void)
{
    FILE * fp;
    char word[MAX];
    int count = 0;

    if ((fp = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stderr, "Can't open the \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }
    rewind(fp);
//    用于确定上次的序号从哪个开始
    while (fgets(word, MAX, fp))
        count++;
    puts("Enter the word you want to add after the file; press the #");
    puts("key at the beginning of a line to terminate");
//    注意%s是字符串的输入 会在末尾自动加入'\0' 所以可以使用puts()函数输出
//    注意fscanf()函数是读取数据 而fprintf()函数是输出数据 在使用两者的时候需要注意文件指针的指向
    while ((fscanf(stdin, "%40s", word) == 1) && word[0] != '#')
    {
        count++;
        fprintf(fp, "This is %d word: %s\n", count, word);
    }
    puts("File contents: ");
//    rewind()函数 返回到文件开始处
    rewind(fp);
//    读取一行输入
    while (fgets(word, MAX, fp))
        fputs(word, stdout);
    puts("Done");
    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");

    return 0;
}