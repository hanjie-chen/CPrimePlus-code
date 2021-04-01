#include <stdio.h>
#include <string.h>

#define SIZE 6

int main(void)
{
    const char * list[SIZE] = {
            "astronomy",
            "astounding",
            "astrophysics",
            "ostracize",
            "asterism",
            "astrophobia"
    };
    int count = 0;
//    注意着第三个参数 限定比较字符个数 并且只比较前面的n位
    for (int i = 0; i < SIZE; ++i)
        if (strncmp(list[i], "astro", 5) == 0)
        {
            printf("Found: %s\n", list[i]);
            count++;
        }
    printf("The list contained %d words beginning with \"astro\".\n", count);

    return 0;
}