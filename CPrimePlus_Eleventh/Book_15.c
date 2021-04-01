#include <stdio.h>

#define SIZE 81

void my_put(const char * string);
unsigned int count_and_put(const char * string);

int main(void)
{
    char words[SIZE] = "apple is good to health";

    my_put(words);
    my_put("Ha ha ha, chj never consider it will use string straightly");
    printf("The total number letter of string words is %u\n", count_and_put(words));

    return 0;
}
void my_put(const char * string)
{
//    while(*string) 相当于 while(*string != '\0')
    while (*string)
        putchar(*string++);
}
unsigned int count_and_put(const char * string)
{
    unsigned int count = 0;

    while (*string)
    {
        putchar(*string++);
        count++;
    }
    putchar('\n');

    return count;
}