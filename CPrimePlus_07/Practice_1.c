#include "stdio.h"
int main(void)
{
    char ch;
    unsigned int space_count = 0;
    unsigned int line_count = 0;
    unsigned int another_count = 0;

    printf("Please enter the word you want to say:\n");
    while ((ch = getchar()) != '#')
    {
        if (ch == ' ')
            space_count++;
        else if (ch == '\n')
            line_count++;
        else
            another_count++;
    }
    printf("The word contains %u space and %u line breaks and %u character", space_count, line_count, another_count);

    return 0;
}