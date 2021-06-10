#include <stdio.h>

// 实际上静态该函数中声明静态变量的语句在程序装入内存的时候已经执行完毕
// 把声明放在函数中只是为了只让该函数看的将该变量
void try_static(void);

int main(void)
{
    for (int i = 1; i < 4; ++i) {
        printf("Here comes iteration %d:\n", i);
        try_static();
    }

    return 0;
}
void try_static(void)
{
//    自动变量 每次函数运行结束自动销毁
    int fade = 1;
//    静态变量 每次结束没有被销毁
    static int stay = 1;

    printf("fade = %d and stay = %d\n", fade++, stay++);
}