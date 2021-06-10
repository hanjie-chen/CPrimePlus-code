#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Practice_3.h"

void Show_Movies(Item item);
void eat_line(void);
char * s_gets(char * string, int n);

int main(void)
{
    List movies;
    Item temp;
//    初始化链表
    InitializeList(&movies);
//    检查链表是否已满
    if (ListIsFull(&movies))
    {
        fprintf(stderr, "No memory available! Bye!\n");
        exit(1);
    }
//    添加链表
    puts("Enter first movie title:");
    while (s_gets(temp.film_name, TITLE_SIZE) != NULL && temp.film_name[0] != '\0')
    {
        puts("Enter your rating:");
        scanf("%d", &temp.rating);
        eat_line();
        if (AddItem(&movies, temp) == false)
        {
            fprintf(stderr, "Something wrong in allocating memory!\n");
            break;
        }
        if (ListIsFull(&movies) == true)
        {
            puts("After the add the list is now full");
            break;
        }
        puts("Enter next movie title(empty line to quit):");
    }
//    输出链表内容
    if (ListIsEmpty(&movies) == true)
        puts("No data entered ! too bad!");
    else
    {
        printf("Here is the movie List:\n");
        Traverse(&movies, Show_Movies);
    }
    printf("There are %d movies.\n", ListItemCount(&movies));
//    清理动态分配的内存
    EmptyTheList(&movies);
    puts("Bye~");

    return 0;
}
void Show_Movies(Item item)
{
    printf("Movie: %s, Rating : %d\n", item.film_name, item.rating);
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
inline void eat_line(void)
{
    while (getchar() != '\n')
        continue;
}