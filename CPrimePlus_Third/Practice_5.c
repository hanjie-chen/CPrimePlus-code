#include "stdio.h"
int main(void)
{
    unsigned int ui_user_age;
    float f_user_age_seconds;
    printf("请输入您的年龄：");
    scanf("%d",&ui_user_age);
    f_user_age_seconds = ui_user_age * 3.156E7;
    printf("您已经活了%e秒钟了\n",f_user_age_seconds);

    return 0;
}