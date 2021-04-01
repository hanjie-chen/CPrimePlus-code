#include <stdio.h>
// 如下为嵌套结构
struct names {
    char first_name[20];
    char last_name[20];
};
struct person1 {
    int id;
    struct names name;
};
// 如下为匿名结构
struct person2 {
    int id;
    struct {
        char first_name[20];
        char last_name[20];
    };
};

int main(void)
{
    struct person1 p1 = {10, {"chen", "Han jie"}};
    struct person2 p2;
    struct person1 * pt;


//    访问p1 first_name 正常访问
    puts(p1.name.first_name);
//    访问p2 first_name 可以将其看为结构的一部分 直接访问
    puts(p2.first_name);

    return 0;
}