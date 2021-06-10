#include <stdio.h>

#define MSG "I'm special"

int main(void)
{
    char array[] = MSG;
    char * pt1 = MSG;
//    pt1指向MSG的地址 而数组拷贝MSG的内容 所以pt1的地址和MSG的地址相同 array则地址不同
//    虽然使用了两次 "I'm special" 但是编译器只使用了一个位置 这由编译器自主选择 别的编译器可以选择存储在一处或者多处
//    静态内存使用的地址 和 动态内存array使用的地址不同
    printf("address of \"I'm a special\" is %p\n", "I'm special");
    printf("              address of array: %p\n", array);
    printf("              address of pt1: %p\n", pt1);
    printf("              address of MSG: %p\n", MSG);
    printf("address of \"I'm a special\" is %p\n", "I'm special");

    return 0;
}