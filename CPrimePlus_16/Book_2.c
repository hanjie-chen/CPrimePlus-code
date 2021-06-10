#include <stdio.h>

#define SQUARE(X) X*X
#define PR(X) printf("The result is %d\n", X)

int main(void)
{
    int x = 5;
    int z;

    printf("x = %d\n", x);
    z = SQUARE(x);
    printf("Evaluating SQUARE(x):");
    PR(z);
    z = SQUARE(2);
    printf("Evaluating SQUARE(2):");
    PR(z);
    printf("Evaluating SQUARE(x + 2):");
    PR(SQUARE(x + 2));
    printf("Evaluating 100 / SQUARE(2):");
    PR(100 / SQUARE(2));
    printf("x is %d\n", x);
    printf("Evaluating SQUARE(++x): ");
    PR(SQUARE(++x));
//    这是因为宏只是替换出现了这样子情况++x*++x所以其递增了两次 而不是像函数那样子先求值在传递参数
    printf("After incrementing, x is %x.\n", x);

    return 0;
}