/* type 2版本更加的简洁 占用的内存也更加的少
 * 但是该版本会保存第一次输入的所有字符串 如果还需要对原本的字符串进行操作那么该版本会更加的合适
 * */
#include <stdio.h>
#include <ctype.h>

#define SIZE 40

void get_word(char input[], char word[], int n);

int main(void)
{
    char word[SIZE];
    char input[SIZE];

    puts("Please enter a word and this program will get the first word")
    fgets(input, SIZE, stdin);
    get_word(input, word, SIZE);
    puts(word);

    return 0;
}
void get_word(char input[], char word[], int n)
{
    _Bool in_word = 0;

    for (int i = 0; i < n; ++i) {
        if (isalpha(input[i]))
        {
            *word = input[i];
            word++;
            in_word = 1;
        }
        else if (!isalpha(input[i]) && in_word)
            break;
    }
}