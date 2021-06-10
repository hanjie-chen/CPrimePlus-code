#include "Book_4.h"
#include <stdio.h>
#include <string.h>

char * s_gets(char * string, int n);
char input_choice(void);
static void eat_line(void);

int main(void)
{
    Queue line;
    Item temp;
    char ch;

    InitializeQueue(&line);
    puts("Testing the Queue interface.");
    while ((ch = input_choice()) != 'q')
    {
        if ('a' == ch)
        {
            if (QueueIsFull(&line))
                puts("Sorry, Queue is Full, can not add person.Please to delete person");
            else{
                puts("Enter the person first name:");
                s_gets(temp.first_name, NAME_SIZE);
                puts("Enter the person last name:");
                s_gets(temp.last_name, NAME_SIZE);
                printf("Putting %s%s into queue\n", temp.first_name, temp.last_name);
                AddQueueItem(temp, &line);
            }
        }
        else if ('d' == ch){
            if (QueueIsEmpty(&line))
                puts("The Queue is empty now, nothing to delete.Please try to add person");
            else{
                DeleteQueueItem(&temp, &line);
                printf("Remove %s%s from queue\n", temp.first_name, temp.last_name);
            }
        }
    }
    EmptyTheQueue(&line);
    puts("Bye~");

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
inline static void eat_line(void)
{
    while (getchar() != '\n')
        continue;
}
char input_choice(void)
{
    char ch;

    puts("Type a to add, d to delete, q to quit");
    while (1)
    {
        ch = getchar();
        eat_line();
        if (strchr("adq", ch) == NULL)
            puts("Please enter only a to add; d to delete; q to quit");
        else
            break;
    }

    return ch;
}