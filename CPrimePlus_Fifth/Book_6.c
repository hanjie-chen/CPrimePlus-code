/* 全局变量定义在main之外，可以给所有的函数使用
 * 定位在main函数中的变量只能给main自己使用，其他函数同理
 * */
#include "stdio.h"
const int Minutes_Seconds = 60; //定义为全局变量，一分钟的秒数
const int Hour_Seconds = 3600; //一个小时的秒数
const double Kilometer_Mile = 0.62137; //一公里的英里数
int main(void)
{
    double distance_kilometer, distance_mile; //行驶的公里数和英里数
    double rate_mile; //平均速度，mile/h
    int minutes,seconds;//跑步用时:以分和秒为单位
    int mile_minutes,mile_seconds; //跑一英里需要的时间，单位：分，秒
    int time; //跑步用时：以秒为单位
    double mile_time; //跑一英里需要的时间，单位：秒

    printf("This program converts your time for a metric race\n");
    printf("to a time for running a mile and to your average \n");
    printf("speed in miles per hour.\n");
    printf("Please enter, in kilometer, the distance run.\n");
    scanf("%lf",&distance_kilometer);
    printf("Next enter the time in minutes and seconds\n");
    printf("Begin by entering the minutes\n");
    scanf("%d",&minutes);
    printf("Now enter the seconds\n");
    scanf("%d",&seconds);

    time = Minutes_Seconds * minutes + seconds; //把时间单位转为秒
    distance_mile = Kilometer_Mile * distance_kilometer; //把公里变为英里
    rate_mile = (distance_mile / time) * Hour_Seconds; //计算出英里每小时
    mile_time = (double) time / distance_mile; //跑1英里所花时间
    mile_minutes = (int) mile_time / Minutes_Seconds; // 求出分钟数
    mile_seconds = (int) mile_time % Minutes_Seconds; // 求出剩余的秒数

    printf("You ran %1.2f km (%1.2f miles) int %d minutes, %d seconds.\n", distance_kilometer, distance_mile, minutes, seconds);
    printf("That pace corresponds to running a mile in %d, ", mile_minutes);
    printf("%d seconds.\n Your average speed was %1.2f mph.\n", mile_seconds, rate_mile);
    return 0;
}