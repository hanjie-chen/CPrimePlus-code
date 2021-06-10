#include <stdio.h>
#include <string.h>

char * s_gets(char * string, int n);

#define MAX_TITLE_LENGTH 41 // 书名最大长度
#define MAX_AUTH_LENGTH 31 // 作者姓名最大长度
// 结构模板 结构的标记为book
struct book
{
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTH_LENGTH];
    float value;
};

int main(void)
{
    struct book library;

    printf("Please enter the book title: \n");
    s_gets(library.title, MAX_TITLE_LENGTH);
    printf("Now enter the author: \n");
    s_gets(library.author, MAX_TITLE_LENGTH);
    printf("Now enter the value: \n");
    scanf("%f", &library.value);
    printf("%s by %s: $%.2f\n", library.title, library.author, library.value);
    printf("%s: \"%s\" ($%.2f) \n", library.author, library.title, library.value);
    puts("Done.");

    return 0;
}
char * s_gets(char * string, int n)
{
    char * result;
    char * find;

    result = fgets(string, n, stdin);
    if (result)
    {
        if ((find = strchr(string, '\n')) != NULL)
            * find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return result;
}