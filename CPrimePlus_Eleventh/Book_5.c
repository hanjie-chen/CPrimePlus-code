#include <stdio.h>

#define S_LEN 40
#define LIM 5

int main(void)
{
//    使用指针数组创建字符串数组
    const char * my_talents[LIM] = {
            "Adding numbers swiftly",
            "Multiplying accurately",
            "Stashing data",
            "Following instructions to the letter",
            "Understanding the C language"
    };
//    使用二维数组创建字符串数组
    char your_talents[LIM][S_LEN] = {
            "Walking in a straight line",
            "Sleeping",
            "Watching television",
            "Mailing letters",
            "Reading email"
    };
//    这两种方式各有利弊请取舍决定
    puts("Let's compare talents:");
    printf("%-36s %-25s\n", "My talents", "Your talents");
    for(int i = 0; i < LIM; ++i)
        printf("%-36s %-25s\n", my_talents[i], your_talents[i]);
    printf("\nsizeof my_talents is %zd, sizeof your_talents is %zd.\n", sizeof(my_talents), sizeof(your_talents));

    return 0;
}