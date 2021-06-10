#include <stdio.h>
#include <string.h>

#define TITLE_SIZE 45 // 电影名称最大长度
#define FILM_MAX 5    // 最大电影数量

typedef struct {
    char film_title[TITLE_SIZE];
    int rating;
} Film;

char * s_gets(char * string, int n);
void eat_line(void); // 函数声明是不需要让用户知道函数的实现

int main(void)
{
    Film movies[FILM_MAX];
    unsigned int input_count = 0;

    puts("Enter first movie title:");
    while (input_count < FILM_MAX && s_gets(movies[input_count].film_title, FILM_MAX) != NULL && movies[input_count].film_title[0] != '\0')
    {
        puts("Enter your rating <0-10>");
        scanf("%d", &movies[input_count++].rating);
        eat_line();
        puts("Next movies title(empty line to quit)");
    }
    if (input_count == 0)
        puts("No data, so bad!");
    else
        puts("Here is the movies list:");
    for (int i = 0; i < input_count; ++i)
        printf("Movie: %s Rating: %d\n", movies[i].film_title, movies[i].rating);
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
            *find = '\0';
        else
            eat_line();
    }

    return result;
}
// 函数实现使用内联函数 这样子加快程序速度
inline void eat_line(void)
{
    while (getchar() != '\n')
        continue;
}