#include <stdio.h>
#include <stdlib.h>

void sign_off(void);
void too_bad(void);

int main(void)
{
    int n;

//    atexit()函数接受一个函数指针作为参数 当main函数退出的时候(exit()) 会调用atexit()注册过的函数
//    其调用顺序和注册顺序相反
    atexit(sign_off); // 注册sign_off函数
    puts("Enter an integer:");
    if (scanf("%d", &n) != 1)
    {
        puts("That's not an integer");
        atexit(too_bad); // 注册too_bad函数
        exit(EXIT_FAILURE);
    }
    printf("%d is %s\n", n, (n % 2 == 0) ? "even" : "odd");

    return 0;
}
void sign_off(void)
{
    puts("This terminates another magnificent program from");
    puts("SeeSaw Software!");
}
void too_bad(void)
{
    puts("SeeSaw Software extends its heartfelt condolences");
    puts("to your upon the failure of your program");
}