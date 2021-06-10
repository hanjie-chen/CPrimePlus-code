#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_TITLE_LEN 40
#define MAX_AUTHOR_LEN 40
#define MAX_BOOKS 10

struct book {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    float value;
    bool is_delete;
};

char * s_gets(char * string, int n);
char Get_Choice(int all_books_count); // 对有可能对错误输入进行处理
int Deal_Exist_Data(struct book *, FILE *, int); // 读取源文件中已有对条目
int Insert_Books(struct book *, int); // 添加图书条目
void Delete_Books(struct book *, int); // 删除图书条目
void Update_Books(struct book *, int); //修改图书条目
void Write_File(struct book *,FILE *, int, int); // 把图书条目写到文件中去
void Print_And_Write_Library(struct book *, FILE *, int, int); // 打印所有图书条目 并且写到文件中去
void Show_Current_Library(struct book *, int); // 打印所有图书条目
void show_menu(int); // 打印选择菜单
void eat_line(void); //  处理多余的字符

int main(void)
{
    struct book library[MAX_BOOKS];
    FILE * fp_books; // 指向数据文件的文件指针
    int all_books_count; // 所有的图书条目 = 已经存在的 + 自己写入的
    int standard_size = sizeof(struct book) - sizeof(bool); // 一条图书条目的大小
    char ch;
//    打开/创建 文件并且重新定位文件指针 如果是r+b的话就不能创建文件了
    if ((fp_books = fopen("book.dat", "r+b")) == NULL)
    {
        fprintf(stderr, "Error in opening the file book.dat.\nPlease check the filename.\n");
        exit(EXIT_FAILURE);
    }
    rewind(fp_books);
//    如果文件中原有以前写过的数据
    all_books_count = Deal_Exist_Data(library, fp_books, standard_size);
//    关闭文件指针
    if (fclose(fp_books) != 0)
        fprintf(stderr, "Error in closing the file book.dat.\n");
    while (1)
    {
        show_menu(all_books_count);
        ch = Get_Choice(all_books_count);
        if ('q' == ch)
            break;
        switch (ch) {
            case 'a': all_books_count = Insert_Books(library, all_books_count);
                break;
            case 'b': Delete_Books(library, all_books_count);
                break;
            case 'c': Update_Books(library, all_books_count);
                break;
            case 'd': Show_Current_Library(library, all_books_count);
                break;
            default:
                break;
        }
    }
//    通过w+b的方式把整个文件给截断为0
    if ((fp_books = fopen("book.dat", "w+b")) == NULL)
    {
        fprintf(stderr, "Error in opening the file book.dat.\n");
        exit(EXIT_FAILURE);
    }
//    列出所有的数据库条目 并且把后续输入的添加到book.dat文件中去
    Print_And_Write_Library(library, fp_books, all_books_count, standard_size);
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
            eat_line();
    }

    return result;
}
char Get_Choice(int all_books_count)
{
    char ch;

    ch = getchar();
    eat_line();
    if (0 == all_books_count)
    {
        while (strchr("aq", ch) == NULL)
        {
            fputs("Please under the guide of menu\n", stdout);
            fputs("Please enter a or q\n", stdout);
            ch = tolower(getchar());
            eat_line();
        }
    }
    else if (MAX_BOOKS == all_books_count)
    {
        while (strchr("bcdq", ch) == NULL)
        {
            fputs("Please under the guide of menu\n", stdout);
            fputs("Please enter b, c, d or q\n", stdout);
            ch = tolower(getchar());
            eat_line();
        }
    } else
    {
        while (strchr("abcdq", ch) == NULL)
        {
            fputs("Please under the guide of menu\n", stdout);
            fputs("Please enter a, b, c, d or q\n", stdout);
            ch = tolower(getchar());
            eat_line();
        }
    }

    return ch;
}
int Deal_Exist_Data(struct book * library, FILE * fp_books, int standard_size)
{
    int exist_books_count = 0; // 已经存在的图书条目

    while (exist_books_count < MAX_BOOKS && fread(&library[exist_books_count], standard_size, 1, fp_books) == 1)
    {
        if (0 == exist_books_count)
            puts("Current contents of book.dat");
        fprintf(stdout, "%s by %s $%.2f\n", library[exist_books_count].title, library[exist_books_count].author, library[exist_books_count].value);
        library[exist_books_count].is_delete = false;
        exist_books_count++;
    }

    return exist_books_count;
}
int Insert_Books(struct book * library, int all_books_count)
{
    puts("Please [enter] at the start of a new line to quit:");
    puts("Now enter new book title.");
    while (all_books_count < MAX_BOOKS && s_gets(library[all_books_count].title, MAX_TITLE_LEN) && library[all_books_count].title[0] != '\0')
    {
        puts("Now enter the author of the book:");
        s_gets(library[all_books_count].author, MAX_AUTHOR_LEN);
        library[all_books_count].is_delete = false;
        puts("Now enter the value of the book:");
        scanf("%f", &library[all_books_count++].value);
        eat_line();
        if (all_books_count < MAX_BOOKS)
            puts("Please enter the next title.");
    }

    return all_books_count;
}
void Delete_Books(struct book * library, int all_books_count)
{
    char temp[MAX_TITLE_LEN];
    bool find = false;

    fputs("Please enter the title of the book you want to delete\n", stdout);
    s_gets(temp, MAX_TITLE_LEN);
    for (int i = 0; i < all_books_count; ++i)
        if (strcmp(temp, library[i].title) == 0 && !library[i].is_delete)
        {
            library[i].is_delete = true;
            find = true;
        }
    if (find)
        fprintf(stdout, "The book %s delete success!\n", temp);
    else
        fputs("Can't find the book you want to find.\nPlease check the title\n", stdout);
}
void Update_Books(struct book * library, int all_book_count)
{
    int location ;
    char temp[MAX_TITLE_LEN];
    bool find = false;

    fputs("Please enter the book title you want to update information\n", stdout);
    s_gets(temp, MAX_TITLE_LEN);
    for (location = 0; location < all_book_count; ++location)
        if (strcmp(temp, library[location].title) == 0 && !library[location].is_delete)
        {
            find = true;
            break;
        }
    if (find)
    {
        fputs("Now enter new book title.\n",stdout);
        s_gets(library[location].title, MAX_TITLE_LEN);
        puts("Now enter the author of the book:");
        s_gets(library[location].author, MAX_AUTHOR_LEN);
        puts("Now enter the value of the book:");
        scanf("%f", &library[location].value);
        eat_line();
    } else
        fputs("Can't find the book you want to find\nPlease check the title you entered.\n", stdout);

}
void eat_line(void)
{
    while (getchar() != '\n')
        continue;
}
void Print_And_Write_Library(struct book * library, FILE * fp_books, int all_books_count, int standard_size)
{
    if (all_books_count > 0)
    {
        Show_Current_Library(library, all_books_count);
        rewind(fp_books);
        Write_File(library, fp_books, all_books_count, standard_size);
    } else
        puts("No books! Too bad!");
    puts("Bye~");
}
void Write_File(struct book * library,FILE * fp_books, int all_books_count, int standard_size)
{
    for (int i = 0; i < all_books_count; ++i)
        if (!library[i].is_delete)
            fwrite(&library[i], standard_size, 1, fp_books);
}
void show_menu(int all_books_count)
{
    if (0 == all_books_count) // 没有任何数据
    {
        fputs("***************************************\n", stdout);
        fputs("* Now the library is empty            *\n", stdout);
        fputs("* a) insert book information  q) quit *\n", stdout);
        fputs("***************************************\n", stdout);
    }
    else if (MAX_BOOKS == all_books_count)// 如果已经将这个结构数组中的内容填满了
    {
        fputs("**********************************************************\n", stdout);
        fputs("* Now the library is full                                *\n", stdout);
        fputs("* b) delete book information  c) update book information *\n", stdout);
        fputs("* d) show current book information q) quit               *\n", stdout);
        fputs("**********************************************************\n", stdout);
    } else // 介于两者之间
    {
        fputs("****************************************************************\n", stdout);
        fputs("* a) insert book information  b) delete book information       *\n", stdout);
        fputs("* c) update book information  d) show current book information *\n", stdout);
        fputs("* q) quit                                                      *\n", stdout);
        fputs("****************************************************************\n", stdout);
    }
    fputs("Please choose one operation\n", stdout);
}
void Show_Current_Library(struct book * library, int all_books_count)
{
    fputs("Here is the list of your books! Please check\n", stdout);
    fputs("+========================================================+\n", stdout);
    for (int i = 0; i < all_books_count; ++i)
        if (!library[i].is_delete)
            printf("= %-30s by %-10s $%-3.2f    =\n", library[i].title, library[i].author, library[i].value);
    fputs("+========================================================+\n", stdout);
}
