#include <stdio.h>

// 这样子声明内联函数是错误的 在调用eat_line()函数的时候不会产生内联的效果
inline static void eat_line(void);
static void eat_line(void)
{
    while (getchar() != '\n')
        continue;;
}
// 这样子定义的内联函数在调用的时候回产生内联的效果
static void line_eat(void);
inline static void line_eat(void)
{
    while(getchar() != '\n')
        continue;
}
// 但是一般的内联函数形式都为如下定义
inline double square(double number)
{
    return number * number;
}
/* 通过上面的例子 我们可以得到下面的结论
 * inline 是用于实现的关键字 而不是用于声明的关键字
 * 这个关键字的主要作用是优化代码 我认为这个关键字不应该出现在声明当中
 * 这是高质量C++/C程序设计的一个基本原则——声明和定义不可以混为一谈 用户没有必要也不需要知道函数是否需要内联
 * */