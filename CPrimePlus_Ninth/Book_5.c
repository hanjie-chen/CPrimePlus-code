#include "stdio.h"
long Loop_Factorial(int number);
long Recursion_Factorial(int number);
void Print_Tips(void);
int main(void)
{
    int number;

    Print_Tips();
    while (1 == scanf("%d", &number))
    {
        if (number < 0)
            printf("No negative number, Please.\n");
        else if (number > 13)
            printf("Keep input under 13.\n");
        else
        {
            printf("loop : %d factorials is %ld\n", number, Loop_Factorial(number));
            printf("recursion: %d factorials is %ld\n", number, Recursion_Factorial(number));
        }
        printf("Enter a value in the range 0~12 (q to quit):");
    }
    printf("Bye~.\n");

    return 0;
}
long Loop_Factorial(int number)
{
    long result = 1;

    for (int i = number; i > 1; --i) {
        result *= i;
    }

    return result;

}
long Recursion_Factorial(int number)
{
    long result;

    if (number > 0)
        result = number * Recursion_Factorial(number -1);
    else
        result = 1;

    return result;
}
void Print_Tips(void)
{
    printf("This program calculates Factorials.\n");
    printf("Enter a value in range 0~12(use 'q' to quit):");
}
