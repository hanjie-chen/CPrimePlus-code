#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define HEIGHT 10
#define LENGTH 80

// 菜单打印函数
void Print_Menu(void);
void Switch(int choose_number, char string_list[][LENGTH], int count);
//下面四个函数是选择和排序函数
void Print_Source_List(char string_list[][LENGTH], int count);
void Print_Sorted_ASCII(char string_list[][LENGTH], int count);
void Print_Sorted_Length(char string_list[][LENGTH], int count);
void Print_Sorted_First_Word(char string_list[][LENGTH], int count);
// 下面几个函数是一些配套函数
int s_input_number(void);
unsigned int first_word_length(char * string);
char * s_gets(char * string, int n);

int main(void)
{
    char string_list[HEIGHT][LENGTH];
    int choose_number;

    puts("This program can do many things");
    while (1)
    {
        unsigned short int count = 0; //用于统计输入了多少条字符串
        puts("Please enter some strings not more than 10 and every string not more than 80 characters:(empty line finish enter)");
//        循环输入10个字符串 或者输入EOF结束
        while (count < HEIGHT && s_gets(string_list[count], LENGTH) && string_list[count][0] != '\0')
            count++;
        printf("%u strings entered\n", count);
        if (count == 0)
        {
            puts("Please enter at least one sentence!!! like: chj is good");
            continue;
        }
        Print_Menu();
        puts("Please enter a number to choose");
        choose_number = s_input_number();
        if (choose_number == 5)
            break;
        Switch(choose_number, string_list, count);
    }
    puts("Bye~");

    return 0;
}

void Print_Menu(void)
{
    puts("This program have 5 functions, Please choose one to show");
    puts("1) print the source string list");
    puts("2) print the string list sorted by ASCII");
    puts("3) print the string list sorted by length increase");
    puts("4) print the string list sorted by first word length increase");
    puts("5) quit");
}
void Switch(int choose_number, char string_list[][LENGTH], int count)
{
    switch (choose_number) {
        case 1:
            Print_Source_List(string_list, count);
            break;
        case 2:
            Print_Sorted_ASCII(string_list, count);
            break;
        case 3:
            Print_Sorted_Length(string_list, count);
            break;
        case 4:
            Print_Sorted_First_Word(string_list, count);
            break;
        default:
            break;
    }
}
// 函数的具体实现
void Print_Source_List(char string_list[][LENGTH], int count)
{
    for (int i = 0; i < count; ++i) {
        puts(string_list[i]);
    }
}
void Print_Sorted_ASCII(char string_list[][LENGTH], int count)
{
    char * sort_string[count];
    char * temp;
//    使用一个指针数组指向该字符串数组 好排序
    for (int i = 0; i < count; ++i)
        sort_string[i] = string_list[i];

//    使用ASCII排序指针 使用选择排序算法
    for (int top = 0; top < count - 1; ++top)
        for (int seek = top + 1; seek < count; ++seek)
            if (strcmp(sort_string[top], sort_string[seek]) > 0)
            {
                temp = sort_string[top];
                sort_string[top] = sort_string[seek];
                sort_string[seek] = temp;
            }

    for (int i = 0; i < count; ++i)
        puts(sort_string[i]);
}
void Print_Sorted_Length(char string_list[][LENGTH], int count)
{
    char * sort_string[count];
    char * temp;

    for (int i = 0; i < count; ++i)
        sort_string[i] = string_list[i];
//    使用选择排序算法来比较
    for (int top = 0; top < count - 1; ++top)
        for (int seek = top + 1; seek < count; ++seek)
            if (strlen(sort_string[top]) > strlen(sort_string[seek]))
            {
                temp = sort_string[top];
                sort_string[top] = sort_string[seek];
                sort_string[seek] = temp;
            }

    for (int i = 0; i < count; ++i)
        puts(sort_string[i]);
}
void Print_Sorted_First_Word(char string_list[][LENGTH], int count)
{
    char * sort_string[count];
    char * temp;

    for (int i = 0; i < count; ++i)
        sort_string[i] = string_list[i];
//    使用选择排序和判断函数来排序
    for (int top = 0; top < count - 1; ++top)
        for (int seek = top + 1; seek < count; ++seek)
            if (first_word_length(sort_string[top]) > first_word_length(sort_string[seek]))
            {
                temp = sort_string[top];
                sort_string[top] = sort_string[seek];
                sort_string[seek] = temp;
            }
    for (int i = 0; i < count; ++i)
        puts(sort_string[i]);

}
// 假装是一条分割线
unsigned int first_word_length(char * string)
{
    _Bool in_word = 0;
    unsigned int first_word_length = 0;

    while (*string)
    {
        if (isalpha(*string))
        {
            first_word_length++;
            in_word = 1;
        }
        else if (!isalpha(*string) && in_word)
            break;
        string++;
    }

    return first_word_length;
}
char * s_gets(char * string, int n)
{
    char * result;
    int i = 0;

    result = fgets(string, n, stdin);
    if (result)
    {
        while (string[i] != '\n' && string[i] != '\0')
            ++i;
        if (string[i] == '\n')
            string[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return result;
}
int s_input_number(void)
{
    int result;

    scanf("%d", &result);
    while (getchar() != '\n')
        continue;

    return result;
}