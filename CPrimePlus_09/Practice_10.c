#include <stdio.h>
long long int Fibonacci_Loop(int number_count);
int main(void)
{
    int number_order;

    printf("This program can calculate the Fibonacci array.\n");
    printf("Now enter the order number of the Fibonacci:(q to quit)\n");
    while (1 == scanf("%d", &number_order))
    {
        printf("Now the number of your order is %lld\n", Fibonacci_Loop(number_order));
        printf("Please enter the order number again(q to quit):\n");
    }
    printf("Bye~.\n");

    return 0;
}
long long int Fibonacci_Loop(int number_count)
{
    long long int number_1 = 1, number_2 = 1;
    long long result = 1;

    if (number_count <= 2)
        return result;
    else
    {
        for (int i = 3; i < number_count; ++i) {
//            如果是偶数的话更新number_2 如果是基数的话更新number_1
            if (i % 2 == 0)
                number_2 = number_1 + number_2;
            else
                number_1 = number_2 + number_1;
        }
    }
    result = number_2 + number_1;

    return result;
}