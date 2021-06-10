#include <stdio.h>

#define PSQR(x) printf("The square of "#x" is %d.\n", ((x)*(x)))
#define X_NAME(n) x ## n
#define PRINT_XN(n) printf("x" #n "= %d\n", x ## n)

int main(void)
{
    int number = 5;
    int X_NAME(1) = 14; // int x1 = 14
    int X_NAME(2) = 20; // int x2 = 20
    int x3 = 30;

//    使用#x可以使其变为输入的参数名称
//    即参数的字符串化
    PSQR(number);
    PSQR(2 + 4);
    PRINT_XN(1);
    PRINT_XN(2);
    PRINT_XN(3);

    return 0;
}