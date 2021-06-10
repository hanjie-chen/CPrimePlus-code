#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STARS "********************************"

int static_store = 30;
const char * pcg = "String Literal";

int main(void)
{
    int auto_store = 40;
    char auto_string[] = "Auto char Array";
    int * pi;
    char * pcl;

    pi = (int *)malloc(sizeof(int));
    *pi = 35;
    pcl = (char *)malloc(strlen("Dynamic String") + 1);
    strcpy(pcl, "Dynamic String");

//    静态数据区域
    puts(STARS);
    printf("static_store: %d at %p\n", static_store, &static_store);
    printf("%s at %p\n", pcg, pcg);
    printf("%s at %p\n", "Quoted String", "Quoted String"); // 注意 字符串字面量也是静态数据
//    动态分配内存变量区域
    puts(STARS);
    printf("* pi: %d at %p\n", *pi, pi);
    printf("%s at %p\n", pcl, pcl);
//    自动分配内存变量区域
    puts(STARS);
    printf("auto_store: %d at %p\n", auto_store, &auto_store);
    printf("%s at %p\n", auto_string, auto_string);
    puts(STARS);
    free(pi);
    free(pcl);

    return 0;
}