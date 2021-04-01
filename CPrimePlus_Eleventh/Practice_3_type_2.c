#include <stdio.h>
#include <ctype.h>

#define SIZE 40

void input_and_get_word(char string[], int n);

int main(void)
{
    char word[SIZE];

    puts("Please enter a sentence not more than 40 characters");
    puts("This program will get the first word");
    input_and_get_word(word, SIZE);
    printf("Now the word is %s\n", word);

    return 0;
}
void input_and_get_word(char string[], int n)
{
    unsigned short int count = 0;
    char ch;
    _Bool in_word = 0; // 为0时意味着在单词之外 为1意味着在单词之内

    while ((ch = getchar()) != '\n' && count <= n)
    {
        count++;
        if (isalpha(ch))
        {
            *string = ch;
            string++;
            in_word = 1;
        }
        else if (!isalpha(ch) && in_word)
            break;
    }

}