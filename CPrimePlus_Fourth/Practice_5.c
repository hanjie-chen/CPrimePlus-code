#include "stdio.h"
int main(void)
{
    float speeds;
    float file_size;
    printf("请输入下载速率：（单位：Mb/s）");
    scanf("%f",&speeds);
    printf("请输入下载的文件大小：（单位：MB）");
    scanf("%f",&file_size);
    printf("At %.2f megabits per second,a file of %.2f megabytes downloads in %.2f seconds.\n",
            speeds,file_size,(file_size * 8)/speeds);
    return 0;
}