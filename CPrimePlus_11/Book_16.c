#include <stdio.h>
#include <string.h>

#define SIZE 88

void fit(char * string, unsigned int size);

int main(void)
{
    char message[] = "Things should be as simple as possible,"
                  "but not simpler";

    puts(message);
    fit(message, 38);
    puts(message);
    puts("Let's look at some more of the strings ");
    puts(message + 39);


    return 0;
}
void fit(char * string, unsigned int size)
{
    if (strlen(string) > size)
        string[size] = '\0';
}