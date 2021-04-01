#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    _Bool in_word = 0;
    unsigned int capital_letters = 0;
    unsigned int lower_letter = 0;
    unsigned int word_count = 0;
    unsigned int punctuation_count = 0;
    unsigned int digital_count = 0;

    puts("This program will count the number of Capital letters and lower letters and punctuation and digital characters and word you entered");
    puts("Enter EOF to quit:");
    while ((ch = getchar()) != EOF)
    {
//        这几个比较好判断 使用自带的函数就ok了
        if (isupper(ch))
            capital_letters++;
        if (islower(ch))
            lower_letter++;
        if (ispunct(ch))
            punctuation_count++;
        if (isdigit(ch))
            digital_count++;

        if (isalpha(ch))
            in_word = 1;
        if (!isalpha(ch) && in_word)
        {
            in_word = 0;
            word_count++;
        }
    }
    printf("You have entered %u Capital letters, %u Lower letters\n", capital_letters, lower_letter);
    printf("You have entered %u punctuations and %u digital characters\n", punctuation_count, digital_count);
    printf("You have entered %u words\n", word_count);

    return 0;
}