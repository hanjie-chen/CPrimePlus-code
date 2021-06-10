#include "stdio.h"
#include "ctype.h"
#include "stdbool.h"
#define STOP '|'
int main(void)
{
    char letter;
    bool judge_word = false;
    unsigned int word_number = 0;
    unsigned int letter_number = 0;
    unsigned int line_number = 1;

    printf("Please enter the paragraph(use '|' to stop enter):\n");
    while ((letter = getchar()) != STOP)
    {
        letter_number++; // 每输入一个字符, 都会递增一次
        if (letter == '\n') // 每输入一个换行符, 就递增一次
            line_number++;
//        if (letter == ' ' || letter == '\t' || letter == '\n') // 每输入一个空白字符, 就递增一次
//            word_number++;
        if (!isspace(letter) && !judge_word) // 使用空白字符检查函数, 更简洁
        {
            judge_word = true;
            word_number++;
        }

        if (isspace(letter) && judge_word)
            judge_word = false;

    }
    printf("The letter of the paragraph is %u\n", letter_number);
    printf("The word of the paragraph is %u\n", word_number);
    printf("The line of the paragraph is %u\n", line_number);

    return 0;
}