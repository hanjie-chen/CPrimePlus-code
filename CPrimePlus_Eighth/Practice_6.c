#include "stdio.h"
#include "ctype.h"
char Get_First(void);
int main(void)
{
    char ch_first;

    printf("Please enter something:\n");
    ch_first = Get_First();
    printf("The first character is %c.\n", ch_first);

    return 0;
}
char Get_First(void)
{
    char ch;
    while ((ch = getchar()) != EOF)
        if (!isspace(ch))
            return ch;
}