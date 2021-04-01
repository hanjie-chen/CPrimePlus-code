#include <stdio.h>
#include <string.h>

#define NAME_LEN 30

struct name_count {
    char first_name[NAME_LEN];
    char last_name[NAME_LEN];
    int letters;
};

void get_info(struct name_count *);
void make_info(struct name_count *);
void show_info(struct name_count *);
char * s_gets(char * string, int n);

int main(void)
{
    struct name_count person;

    get_info(&person);
    make_info(&person);
    show_info(&person);

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
void get_info(struct name_count * pst)
{
    printf("Please enter your first name:\n");
    s_gets(pst->first_name, NAME_LEN);
    printf("Please enter your last name:\n");
    s_gets(pst->last_name, NAME_LEN);

}
void make_info(struct name_count * pst)
{
    pst->letters = strlen(pst->last_name) + strlen(pst->first_name);
}
void show_info(struct name_count * pst)
{
    printf("%s %s your name contains %d letters.\n", pst->first_name, pst->last_name, pst->letters);
}