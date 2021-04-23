#include <stdio.h>
#include "Book_5.h"

void get_names(names * ps)
{
    puts("Please enter your first name");
    s_gets(ps->first_name, S_LEN);
    puts("Please enter your last name");
    s_gets(ps->last_name, S_LEN);
}
void show_names(const names * ps)
{
    printf("%s %s", ps->first_name, ps->last_name);
}
char * s_gets(char * string, int n)
{
    char * result;
    char * find;

    result = fgets(string, S_LEN, stdin);
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