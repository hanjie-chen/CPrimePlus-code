#include <stdio.h>
#include <string.h>

#define NAME_LEN 30

struct name_count {
    char first_name[NAME_LEN];
    char last_name[NAME_LEN];
    int letters;
};

struct name_count get_info(void);
struct name_count make_info(struct name_count);
void show_info(struct name_count);
char * s_gets(char * string, int n);

int main(void)
{
    struct name_count person;

    person = get_info();
    person = make_info(person);
    show_info(person);

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
struct name_count get_info(void)
{
    struct name_count temp;

    printf("Please enter your first name:\n");
    s_gets(temp.first_name, NAME_LEN);
    printf("Please enter your last name:\n");
    s_gets(temp.last_name, NAME_LEN);

    return temp;
}
struct name_count make_info(struct name_count temp)
{
    temp.letters = strlen(temp.first_name) + strlen(temp.last_name);

    return temp;
}
void show_info(struct name_count temp)
{
    printf("%s %s your name contains %d letters.\n", temp.first_name, temp.last_name, temp.letters);
}