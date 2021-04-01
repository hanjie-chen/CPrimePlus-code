/*有关printf函数的原理和出现的问题原因，可以参考书本上C Prime Plus 77页
 *
 * */
#include "stdio.h"
int main(void)
{
    int i_number = 336;
    int record;
    float f_number = 336.5;
    printf("当转换不匹配是会发生什么？\n");
//    由于单个字符的存储位数为2个字节，即0~255之间，当数字超出这个位数的时候，会取最后两位字节来代表字符
    printf("number as int is %d as char is %c\n",i_number,i_number);
    printf("当整数和浮点数混淆的时候会发生什么？\n");
    printf("int express as float is %f,float express as int is %d\n",i_number,f_number);
//    printf函数也是由返回值的，返回打印了几个符号，包括了特殊符号，如果输出有错，那么会返回一个负值
    record = printf("%d,%.2f\n",i_number,f_number);
    printf("the printf return %d\n",record);
    return 0;
}