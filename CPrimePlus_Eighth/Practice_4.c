#include "stdio.h"
#include "ctype.h"
#include "stdbool.h"
int main(void)
{
    char ch;
    bool in_word = false;
    unsigned int word_count = 0;
    unsigned int letter_count = 0;

    printf("Please enter the word you want to say:\n");
    while ((ch = getchar()) != EOF)
    {
        if (isalpha(ch))
        {
            letter_count++;
            if (!in_word)
            {
                word_count++;
                in_word = true;
            }
        } else
            in_word = false;

    }
    printf("You have enter %d letters.\n", letter_count);
    printf("You have enter %d words.\n", word_count);
    printf("So average letter of every word you input is %.2f", (float)letter_count / word_count);

    return 0;
}