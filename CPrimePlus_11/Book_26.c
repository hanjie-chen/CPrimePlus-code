#include <stdio.h>
#include <string.h>

#define SIZE 81
#define LIM 20

void sort_string(char *string[], int number);
char * s_gets(char *string, int n);

int main(void)
{
    char input[LIM][SIZE];
    char * pt_string[LIM];
    int ct = 0;

    printf("Please input at most %d lines, and I will sort them.\n", LIM);
    printf("Please press enter key at a line's start to stop.\n");
    while (ct < LIM && (s_gets(input[ct], SIZE) != NULL) && (input[ct][0] != '\0'))
    {
        pt_string[ct] = input[ct];
        ++ct;
    }
    sort_string(pt_string, ct);
    puts("Here's the sort list:");
    for (int i = 0; i < ct; ++i) {
        puts(pt_string[i]);
    }

    return 0;
}
char * s_gets(char *string, int n)
{
    char * ret_val;
    int i = 0;

    ret_val = fgets(string, n, stdin);
    if (ret_val)
    {
        while (string[i] != '\0' && string[i] != '\n')
            ++i;
        if (string[i] == '\n')
            string[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}
void sort_string(char *string[], int number)
{
    char * temp;
    int top, seek;

    for (top = 0; top < number - 1; ++top)
        for (seek = top + 1; seek < number; seek++)
            if (strcmp(string[top], string[seek]) > 0)
            {
                temp = string[top];
                string[top] = string[seek];
                string[seek] = temp;
            }
}