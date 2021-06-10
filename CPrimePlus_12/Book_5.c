#include <stdio.h>

// 定义式声明 为变量预留了存储空间
int units = 0;

void critic(void);

int main(void)
{
//    引用式声明 告诉编译器使用之前已经定义过的变量
//    使用extern关键字不会引起内存的分配 它指示编译器去别处查询定义
    extern int units;

    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &units);
    while (units != 56)
        critic();
    printf("You must have looked it up\n");

    return 0;
}
void critic(void)
{
    printf("No luck, my friend. Try again.\n");
    scanf("%d", &units);
}