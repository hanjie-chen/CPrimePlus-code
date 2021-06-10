#include <stdio.h>
// 泛型选择 -- 匹配变量类型
#define MYTYPE(X) _Generic((X), int: "int", float: "float", double: "double", default: "other")

int main(void)
{
    int number = 5;

    printf("%s\n", MYTYPE(number));
    printf("%s\n", MYTYPE(2.0 * number));
    printf("%s\n", MYTYPE(3L));
    printf("%s\n", MYTYPE(&number));

    return 0;
}