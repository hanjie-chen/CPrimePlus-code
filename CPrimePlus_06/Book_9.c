#include "stdio.h"
int main(void)
{
    const int secret_code = 13;
    int enter_code;
//    do while 循环至少会执行一次，虽然下面的代码也可是使用while来实现
    do {
        printf("To enter the fuck therapy club !,\n ");
        printf("please enter rhe secret code number:");
        scanf("%d", &enter_code);
    }while (enter_code != secret_code);
    printf("Congratulation! You are cubed");
    return 0;
}