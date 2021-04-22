#include <stdio.h>
#include <math.h>

#define PR(X, ...) printf("Message " #X ":" __VA_ARGS__)

int main(void)
{
    double number1 = 48;
    double number2;

    number2 = sqrt(number1);
    PR(1, "number1 = %g\n", number1);
    PR(2, "number2 = %.2f, number2 = %.4f\n", number1, number2);


    return 0;
}