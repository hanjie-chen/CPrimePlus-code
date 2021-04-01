#include <stdio.h>
#include <string.h>

#define SIZE 40
#define WORD "beast"

int main(void)
{
    const char * orig = WORD;
    char copy[SIZE] = "Be the best that you can be";
    char * ps;

    puts(orig);
    puts(copy);
    ps = strcpy(copy + 7, orig);
    puts(copy);
    puts(ps);
//    注意 strcpy拷贝的时候会把'\0'也拷贝进去
    puts(ps + 6);

    return 0;
}