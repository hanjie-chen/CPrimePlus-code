#include <stdio.h>

// 如果未初始化静态变量 那么会被自动初始化为0
// 不能使用变量来初始化文件作用域变量

int Erupt; // 外部链接的静态变量
double Up[100]; // 外部链接的静态变量
extern char Coal;  // 如果Coal被定义在另外一个翻译单元中 那么必须在前面加入关键字extern

void next(void);

int main(void)
{
    printf("%d\n", Erupt);
    return 0;
}
int Poc; // 在next函数中可用 在main中不可用 因为定义在main之后

void next(void)
{

}