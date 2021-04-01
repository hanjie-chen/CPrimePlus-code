#include <stdio.h>
#include <string.h>

char * s_gets(char * string, int n);

#define MAX_TITLE_LENGTH 40
#define MAX_AUTHOR_LENGTH 40
#define MAX_BOOKS 100

struct book{
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    float value;
};

int main(void)
{
    struct book library[MAX_BOOKS];
    int count = 0;
    
    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to quit.\n");
//    一个while循环用于输入数据库条目
    while (count < MAX_BOOKS && s_gets(library[count].title, MAX_TITLE_LENGTH) && library[count].title[0] != '\0')
    {
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAX_AUTHOR_LENGTH);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;
        if (count < MAX_BOOKS)
            printf("Please enter the next title.\n");
    }
//    如果输入了图书条目
    if (count > 0)
    {
        printf("Here is the list of your books:\n");
        for (int i = 0; i < count; ++i)
            printf("%s by %s: $%.2f\n", library[i].title, library[i].author, library[i].value);
    } else
        printf("No books, Too bad.\n");
    
    return 0;
}
char * s_gets(char * string, int n)
{
    char * result;
    char * find;

    result = fgets(string, n, stdin);
    if (result)
    {
        find = strchr(string, '\n');
        if (find)
            * find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return result;
}