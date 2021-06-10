#include <stdio.h>

#define Harmonic_Mean(X, Y) (1.0 / (((1.0 / (X)) + (1.0 / (Y))) / 2.0))

int main(void)
{
    int number_first, number_second;

    puts("Please enter two integer and 'q' to quit:");
    while (scanf("%d %d", &number_first, &number_second) == 2)
    {
        printf("The Harmonic mean of %d and %d is %.2f\n", number_first, number_second, Harmonic_Mean(number_first, number_second));
        puts("Please enter next pair number:");
    }
    puts("Bye~");

    return 0;
}