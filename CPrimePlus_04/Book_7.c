/* scanf的转化说明见书本上80页
 * */
#include "stdio.h"
int main(void)
{
    int i_number;
    float f_number;
    char string[40];
//    scanf读取基本变量是需要加上一个&，scanf读取字符数组的时候，不需要使用&
    printf("请输入基本变量类型：（整形数+浮点数）");
    scanf("%d%f",&i_number,&f_number);
    printf("请输入字符数组类型：（一串字符串）");
    scanf("%s",string);
    printf("The int number is %d,The float number is %f\n",i_number,f_number);
    printf("The string is %s",string);
    return 0;
}