#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LEN 40
#define MAX_AUTHOR_LEN 40
#define MAX_BOOKS 10

char * s_gets(char * string, int n);

struct book {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    float value;
};

int main(void)
{
    struct book library[MAX_BOOKS];
    FILE * fp_books; // 指向数据文件的文件指针
    int all_books_count = 0; // 所有的图书条目 = 已经存在的 + 自己写入的
    int exist_books_count = 0; // 已经存在的图书条目
    int standard_size = sizeof(struct book); // 一个结构体的大小

    if ((fp_books = fopen("book.dat", "a+b")) == NULL)
    {
        fprintf(stderr, "Error in opening the file book.dat.\nPlease check the filename.\n");
        exit(EXIT_FAILURE);
    }
    rewind(fp_books);
//    如果文件中原有以前写过的数据
    while (exist_books_count < MAX_BOOKS && fread(&library[exist_books_count], standard_size, 1, fp_books) == 1)
    {
        if (0 == exist_books_count)
            puts("Current contents of book.dat");
        fprintf(stdout, "%s by %s $%.2f\n", library[exist_books_count].title, library[exist_books_count].author, library[exist_books_count].value);
        exist_books_count++;
    }
//    如果已经将这个结构数组中的内容填满了
    if (MAX_BOOKS == exist_books_count)
    {
        fputs("Now the file book.dat is full", stderr);
        exit(EXIT_FAILURE);
    }
//    所有书的计数从原来的已经存在的条目开始计数
    all_books_count = exist_books_count;
//    输入后续要加上的条目
    puts("Now add new book title.");
    puts("Please [enter] at the start of a new line to quit:");
    while (all_books_count < MAX_BOOKS && s_gets(library[all_books_count].title, MAX_TITLE_LEN) && library[all_books_count].title[0] != '\0')
    {
        puts("Now enter the author of the book:");
        s_gets(library[all_books_count].author, MAX_AUTHOR_LEN);
        puts("Now enter the value of the book:");
        scanf("%f", &library[all_books_count++].value);
        while (getchar() != '\n')
            continue;
        if (all_books_count < MAX_BOOKS)
            puts("Please enter the next title.");
    }
//    列出所有的数据库条目 并且把后续输入的添加到book.dat文件中去
    if (all_books_count > 0)
    {
        puts("Here is the list of your books! Please check");
        for (int i = 0; i < all_books_count; ++i)
            printf("%s by %s $%.2f\n", library[i].title, library[i].author, library[i].value);
        fwrite(&library[exist_books_count], standard_size, all_books_count - exist_books_count, fp_books);
    } else
        puts("No books! Too bad!");
    puts("Bye~");
    if (fclose(fp_books) != 0)
        fprintf(stderr, "Error in closing the file book.dat.\n");
    
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