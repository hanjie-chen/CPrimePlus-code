#include "stdio.h"
int main(void)
{
    int number;
    int judge_prime = 1;

    printf("Please enter a integer(enter a 'q' to quit):");
    while (scanf("%d", &number) == 1)
    {
        judge_prime = 1;
        for (int i = 2; i * i <= number; ++i) {
            if (number % i == 0)
            {
                if (i * i == number)
                    printf("%d is divide by %d\n", number, i);
                else
                    printf("%d is divide by %d and %d\n", number, i, number / i);
                judge_prime = 0;
            }
        }
        if (judge_prime == 1)
            printf("Sorry %d is a prime number, which means it don't have divisor\n", number);
        printf("Please enter a integer(enter a 'q' to quit):");
    }
    printf("Bye~\n");

    return 0;
}