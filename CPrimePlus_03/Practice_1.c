#include "stdio.h"
#include "stdbool.h"
int main(void)
{
    int max_int = 2147483647;//对于32/64位系统而言int为4字节：2^31 = 2147483648;对于16位系统而言，int为2字节：2^15 = 324768
    printf("%d\n",max_int);
    printf("%d\n",max_int+1);
    printf("The size of int is %zd\n",sizeof(int)); //用于跨系统使用%zd，不用担心溢出的问题
    float max_float = 3.4E38; //表示科学计数法
    float min_float = 1.234E-38;
    printf("%e\n",max_float);  //%e表示科学计数法来表达这个值
    printf("%e\n",max_float * 10);//inf 的含义是无穷大
    printf("%e\n",min_float);
    printf("%e\n",min_float / 1000); //由于下溢导致的精度开始出现偏差
    printf("The size of float is %zd\n",sizeof(float));
    return 0;
}