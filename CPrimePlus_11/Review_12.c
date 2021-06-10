#include <stdio.h>

char * Find_Space(char * string);

int main(void)
{
    char str1[40] = "apple is good";
    char str2[40] = "ooh!!!";
    char * ptr1;
    char * ptr2;

    ptr1 = Find_Space(str1);
    ptr2 = Find_Space(str2);

    if (ptr1)
        printf("Find Space at %p\n", ptr1);
    if (!ptr2)
        printf("Can't Find Space\n");

    return 0;
}
char * Find_Space(char * string)
{
    char * result;

    result = string;
    while (*result != '\0')
    {
        if (*result == ' ')
            break;
        result++;
    }
    if (* result == '\0')
        result = NULL;

    return result;
}