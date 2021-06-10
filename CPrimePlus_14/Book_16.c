#include <stdio.h>
// 下面两条语句的作用相同 但是机理不同
// typedef 有编译器结束 define 则为预处理
typedef unsigned char BYTE1 ;
#define BYTE2 unsigned char
// 注意下面两条语句的是不同的
typedef char * STRING_POINTER1;
#define STRING_POINTER2 char *
// 当使用typedef来给结构体自定义名称时可以省去结构体的标签
typedef struct complex1{
    float real1;
    float imag1;
}COMPLEX1;
typedef struct {
    float real2;
    float imag2;
}COMPLEX2;

int main(void)
{
    BYTE1 number1;
    BYTE2 number2;
    char word[50] = "apple is good company";
    STRING_POINTER1 pt1, pt2; // 相当于char * pt1, * pt2;
    STRING_POINTER2 pt3, pt4; // 相当于char * pt3, pt4; pt3是指针 但是pt4不是
    COMPLEX1 c1 = {2.4, 3.6};
    COMPLEX1 c2;

    number1 = 255;
    number2 = 20;
    printf("%u %u\n", number1, number2);

    pt1 = word;
    pt2 = word;
    pt3 = word;
    pt4 = word[0];
    printf("%s\n%s\n%s\n%c\n", pt1, pt2, pt3, pt4);

    c2 = c1;

    return 0;
}