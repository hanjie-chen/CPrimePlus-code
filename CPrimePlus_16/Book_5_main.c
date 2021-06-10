#include <stdio.h>
#include "Book_5.h"

int main(void)
{
    names candidate;

    get_names(&candidate);
    printf("Let's welcome");
    show_names(&candidate);
    puts("to this program");

    return 0;
}