#include <stdio.h>
#include <math.h>
// 注意下面的宏需要放在assert.h头文件的前面
// 当定义了这个宏之后 则认为程序已经排除了所有的bug 于是编译器会禁用文件中所有的assert()语句
#define NDEBUG
#include <assert.h>



int main(void)
{
    double number1, number2;
    double result;

    puts("Enter a pair of numbers (0 0 to quit): ");
    while (scanf("%lf%lf", &number1, &number2) == 2 && (number1 != 0 || number2 != 0))
    {
        result = number1 * number1 - number2 * number2; //错误的表达式应该是+号
//        当没有满足这个表达式的时候assert就会断言——退出程序并且一种标准格式的错误
        assert(result > 0);
        printf("answer is %f\n", sqrt(result));
        printf("Next pair of numbers:\n");
    }
    puts("Bye~");

    return 0;
}