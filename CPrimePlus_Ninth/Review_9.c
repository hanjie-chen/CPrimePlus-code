#include <stdio.h>
void Show_Menu(void);
int Get_Choice(int max, int min);
void Doing_Job(int choice);
int main(void)
{
    int choice;

    Show_Menu();
    while ((choice = Get_Choice(4, 1)) != 4)
    {
        Doing_Job(choice);
        Show_Menu();
    }

    printf("Bye~.\n");

    return 0;
}
void Show_Menu(void)
{
    printf("Please choose one of the following:\n");
    printf("1) copy files     2) move files\n");
    printf("3) remove files   4) quit\n");
    printf("Enter the number of your choice.\n");
}
int Get_Choice(int max, int min)
{
    int choice;
    int status;

    while ((status = scanf("%d", &choice)) != 1 ||choice < min || choice > max)
    {
        if (1 != status)
        {
            scanf("%*s"); // 这个其实没有必要
            choice = 4;
            break;
        }
        Show_Menu();
        printf("Warning !! Please enter a integer from %d to %d\n", max, min);
    }

    return choice;
}
void Doing_Job(int choice)
{
    switch (choice) {
        case 1:
            printf("*******************.\n");
            printf("Copy successfully.\n");
            printf("*******************.\n");
            break;
        case 2:
            printf("*******************.\n");
            printf("Move file successfully.\n");
            printf("*******************.\n");
            break;
        case 3:
            printf("*******************.\n");
            printf("Remove file successfully.\n");
            printf("*******************.\n");
            break;
        default:
            printf("*******************.\n");
            printf("Error, something bad is happened.\n");
            printf("*******************.\n");
            break;
    }
}