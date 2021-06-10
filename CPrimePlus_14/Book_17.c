#include <stdio.h>
#include <stdlib.h>

int main(void)
{
//    注意函数声明的位置
    void ToUpper(char *);
    void ToLower(char *);
    int round(double );
//    pf是一个指向函数的指针
    void (* pf)(char *);
    char mis [] = "Nina Metier";

//    两种形式的函数指针使用方式都成立 个人更喜欢第二种 更加的简洁
    pf = ToUpper;
    (*pf)(mis);
    pf = ToLower;
    pf(mis);
//    注意pf不可以指向round因为返回值的类型不同
    pf = round;

    return 0;
}