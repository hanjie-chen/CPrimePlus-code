#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITLE_SIZE 45

// 注意虽然使用typedef来重命名该结构 本不需要 film 字段 但是为了在结构值包含一个指向该结构的指针 还是需要该字段的
// 结构不可以包含与本身类型相同的结构 但是可以含有指向相同结构的指针
typedef struct film {
    char film_title[TITLE_SIZE];
    int rating;
    struct film * next;
} Film;

char * s_gets(char * string, int n);
void eat_line(void);
int main(void)
{
    Film * head = NULL;
    Film * previous, * current;
    char input[TITLE_SIZE];

    puts("Enter first movies title:");
    while (s_gets(input, TITLE_SIZE) != NULL && input[0] != '\0')
    {
//        申请一块动态内存区域来存放一部电影信息 该内存的地址指向current
        current = (Film *) malloc(sizeof(Film));
//        如果链表第一块区域为NULL 说明是第一次申请内存 head指向current
//        如果不是第一块区域那么上一块区域的指针指向这一块区域
        if (head == NULL)
            head = current;
        else
            previous->next = current;
//        默认当前的块是最后一块 设置下一个指针为NULL
        current->next = NULL;
//        输入当前块的信息
        strcpy(current->film_title, input);
        puts("Enter your rating <0-10>");
        scanf("%d", &current->rating);
        eat_line();
//        当前块的信息输入结束 当前块变为上一个块
        previous = current;
        puts("Enter the next movies title(empty line to quit)");
    }
    if (head == NULL)
        puts("No data, too bad!");
    else
        puts("Here is the movies list:");
//    重置指针指向最开始的那块区域
    current = head;
    while (current != NULL)
    {
        printf("Movie: %s Rating: %d\n", current->film_title, current->rating);
        current = current->next;
    }
//    重置指针指向最开始的头指针
    current = head;
//    不断释放头指针指向的区域
    while (current != NULL)
    {
//        头指针指向下一块区域
        head = current->next;
//        释放本块区域
        free(current);
//        current 指针指向
        current = head;
    }
    puts("The memory is cleared!");

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
inline void eat_line(void)
{
    while (getchar() != '\n')
        continue;
}