#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 40
#define ARRAY_LENGTH 5

typedef struct {
    char first_name[NAME_LEN];
    char last_name[NAME_LEN];
} names;

void show_array(const names *, int);
int my_compare(const void * p1, const void * p2);

int main(void)
{
    names member[ARRAY_LENGTH] = {
            {"chen", "han jie"},
            {"guo", "jia"},
            {"chen", "hao yang"},
            {"yi", "jia hun"},
            {"chen", "qiang"}
    };
    puts("The current list:");
    show_array(member, ARRAY_LENGTH);
    qsort(member, ARRAY_LENGTH, sizeof(names), my_compare);
    puts("After the quit sort the list is:");
    show_array(member, ARRAY_LENGTH);

    return 0;
}
void show_array(const names * ps, int size)
{
    for (int i = 0; i < size; ++i)
        printf("The member-%d is %s %s\n", i + 1, ps[i].first_name, ps[i].last_name);
    putchar('\n');
}
int my_compare(const void * p1, const void * p2)
{
    const names * a1 = (const names *)p1;
    const names * a2 = (const names *)p2;
    int result;
//    首先比较姓 如果不相同则返回值 然后比较名
    result = strcmp(a1->first_name, a2->first_name);
    if (result != 0)
        return result;
    else
        return strcmp(a1->last_name, a2->last_name);
}