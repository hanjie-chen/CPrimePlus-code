#include <stdio.h>
#include <string.h>

#define MAX_TITLE_LENGTH 40
#define MAX_AUTHOR_LENGTH 40
#define MAX_BOOKS 100

struct book{
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    float value;
};

char * s_gets(char * string, int n);
void Print_Library(void (*pf)(struct book library[], int array[], int count), struct book library[], int count);
void Input_Sort(struct book library[], int array[], int count);
void Title_Sort(struct book library[], int array[], int count);
void Price_Sort(struct book library[], int array[], int count);

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
        printf("Here is the list of your books ordered by input sequence:\n");
        Print_Library(Input_Sort, library, count);
        printf("Here is the list of your books ordered by book title sequence:\n");
        Print_Library(Title_Sort, library, count);
        printf("Here is the list of your books ordered by book price sequence:\n");
        Print_Library(Price_Sort, library, count);
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
void Print_Library(void (*pf)(struct book library[], int array[], int count), struct book library[], int count)
{
    int array[count];
//    初始化输出序列号
    for(int i = 0; i < count; ++i)
        array[i] = i;
//    对排序数组进行处理 使其变为我们想要的序列
    pf(library, array, count);
    for (int i = 0; i < count; ++i)
        printf("%s by %s: $%.2f\n", library[array[i]].title, library[array[i]].author, library[array[i]].value);
}
void Input_Sort(struct book library[], int array[], int count)
{
//    do nothing
}
void Title_Sort(struct book library[], int array[], int count)
{
    int temp;
//    使用选择排序
    for (int top = 0; top < count - 1; ++top)
        for (int seek = top + 1; seek < count; ++seek)
            if (strcmp(library[top].title, library[seek].title) < 0)
            {
                temp = array[top];
                array[top] = array[seek];
                array[seek] = temp;
            }
}
void Price_Sort(struct book library[], int array[], int count)
{
    int temp;

    for (int top = 0; top < count - 1; ++top)
        for (int seek = top + 1; seek < count; ++seek)
            if (library[top].value < library[seek].value)
            {
                temp = array[top];
                array[top] = array[seek];
                array[seek] = temp;
            }
}