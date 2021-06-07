#include "Practice_7.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PrintMenu(void);
void ShowItem(Item temp);
void FindWord(Tree * point_tree);
static void eat_line(void);
char GetChoice(void);
char * s_gets(char * string, int n);

int main(void)
{
    Tree word_list;
    FILE * fp;
    Item temp;
    char choice;

    if ((fp = fopen("Practice_7_test", "r")) == NULL)
    {
        fputs("Error in opening the file!", stderr);
        exit(EXIT_FAILURE);
    }
//    初始化一棵二叉树
    InitializeTree(&word_list);
//    将文件里面的单词写入二叉树中
    while (fscanf(fp, "%s", temp.word) == 1)
    {
        temp.word_count = 1;
        AddTreeNode(&temp, &word_list);
    }
    PrintMenu();
    while ((choice = GetChoice()) != 'q')
    {
        switch (choice) {
            case 'a':Traverse(&word_list, ShowItem);break;
            case 'b':FindWord(&word_list);break;
            default:break;
        }
        PrintMenu();
    }
    DeleteAll(&word_list);
    fputs("Everything is finish! Bye~", stdout);

    return 0;
}
void PrintMenu(void)
{
    puts("**********************************************************************");
    puts("* a) list all the word in file and its appeared times count          *");
    puts("* b) Enter a word and I will tell your the word appeared times count *");
    puts("* q) quit the program                                                *");
    puts("**********************************************************************");
}
void ShowItem(Item temp)
{
    printf("The word %s, it appeared %d times\n", temp.word, temp.word_count);
}
char GetChoice(void)
{
    char ch;

    ch = getchar();
    eat_line();
    while (strchr("abq", ch) == NULL)
    {
        puts("Please enter only a or b or q, not other letter!");
        ch = getchar();
        eat_line();
    }

    return ch;
}
static inline void eat_line(void)
{
    while (getchar() != '\n')
        continue;
}
void FindWord(Tree * point_tree)
{
    Item temp;

    puts("Please enter the word you want to find");
    s_gets(temp.word, WORD_SIZE);
    if (InTree(&temp, point_tree))
        printf("The word %s appeared %d times\n", temp.word, temp.word_count);
    else
        printf("Can not find the word you entered, please check\n");

}
char * s_gets(char * string, int n)
{
    char * result;
    char * find;

    result = fgets(string, n, stdin);
    if (result)
    {
        find = strchr(string, '\n');
        if (find)
            * find = '\0';
        else
            eat_line();
    }

    return result;
}