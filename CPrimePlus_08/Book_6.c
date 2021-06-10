#include "stdio.h"
char Get_Choice(void);
char Get_First(void);
int Get_Int(void);
void Count(void);
int main(void)
{
    int choice;

    while ((choice = Get_Choice()) != 'q')
    {
        switch (choice) {
            case 'a':
                printf("Buy low, sell high\n");
                break;
            case 'b':
                printf("Wall\a");
                break;
            case 'c':
                Count();
                break;
            default:
                printf("Program error!\n");
                break;
        }
    }
    printf("Bye~.\n");

    return 0;
}
char Get_Choice(void)
{
    char ch;

    printf("Enter the letter to choose.\n");
    printf("a: advice      b:bell.\n");
    printf("c: count       q:quit.\n");
    ch = Get_First();
    while ((ch < 'a' || ch > 'c') && ch != 'q')
    {
        printf("Please respond whit a, b, c, or q.\n");
        ch = Get_First();
    }

    return ch;
}
char Get_First(void)
{
    char ch;

    ch = getchar();
    while (getchar() != '\n')
        continue;

    return ch;
}
int Get_Int(void)
{
    int input;
    char ch;

    while (scanf("%d", &input) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not a integer.\n");
        printf("Please enter a integer such as -178, 67, 3:");
    }

    return input;
}
void Count(void)
{
    int n;

    printf("Count how far? Enter an integer:");
    n = Get_Int();
    for (int i = 0; i <= n; ++i) {
        printf("%d\n", i);
    }
    while (getchar() != '\n')
        continue;
}