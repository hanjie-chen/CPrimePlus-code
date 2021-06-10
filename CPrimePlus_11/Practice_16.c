#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 40
#define Simple_Print "-p"
#define Capital_Print "-u"
#define Lower_Print "-l"

void To_Capital_String(char * string);
void To_Lower_String(char * string);

int main(int argc, char *argv[])
{
    char string[SIZE];
    int i = 0;

    puts("Please enter a sentence not more than 40 letters");
    while ((string[i] = getchar()) != EOF)
        ++i;
    string[i] = '\0';

    if (argc == 1 || strcmp(argv[1], Simple_Print) == 0)
        puts(string);
    else if (strcmp(argv[1], Capital_Print) == 0)
    {
        To_Capital_String(string);
        puts(string);
    }
    else if (strcmp(argv[1], Lower_Print) == 0)
    {
        To_Lower_String(string);
        puts(string);
    }

    return 0;
}
void To_Capital_String(char * string)
{
    while (*string)
    {
        if (islower(*string))
            *string = toupper(*string);
        string++;
    }
}
void To_Lower_String(char * string)
{
    while (*string)
    {
        if (isupper(*string))
            *string = tolower(*string);
        string++;
    }
}