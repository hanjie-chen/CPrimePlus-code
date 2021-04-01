#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_LEN 30

struct name_count {
    char * first_name;
    char * last_name;
    int letters;
};

void get_info(struct name_count *);
void make_info(struct name_count *);
void show_info(struct name_count *);
void cleanup(struct name_count *);
char * s_gets(char * string, int n);

int main(void)
{
    struct name_count person;

    get_info(&person);
    make_info(&person);
    show_info(&person);
    cleanup(&person);

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
    char temp[NAME_LEN];
//    给first name动态分配内存
    printf("Please enter your first name:\n");
    s_gets(temp, NAME_LEN);
//    注意strlen()函数只计算字符的的个数 并没有把\0计算入内 所以需要+1
    pst->first_name = (char *)malloc(sizeof(char) * (strlen(temp) + 1));
    strcpy(pst->first_name, temp);
    printf("Please enter your last name:\n");
    s_gets(temp, NAME_LEN);
    pst->last_name = (char *)malloc(sizeof(char) * (strlen(temp) + 1));
    strcpy(pst->last_name, temp);

}
void make_info(struct name_count * pst)
{
    pst->letters = strlen(pst->last_name) + strlen(pst->first_name);
}
void show_info(struct name_count * pst)
{
    printf("%s %s your name contains %d letters.\n", pst->first_name, pst->last_name, pst->letters);
}
void cleanup(struct name_count * pst)
{
    free(pst->first_name);
    free(pst->last_name);
}