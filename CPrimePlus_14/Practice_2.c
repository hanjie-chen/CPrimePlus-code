#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MONTH 12
#define LEN 10
// 用于保存用户输入的信息
struct exact_date {
    int year;
    char month[LEN];
    int days;
};
// 用于保存一年之中的月份信息 月份名 月份缩写 天数 序号
struct month_info{
    char mouth_name[20];
    char mouth_abb[4];
    int days;
    int sequence;
};
// 一个初始化的结构数组 不能直接使用 因为2月被初始化为一个错误的值
struct month_info year[MONTH] = {
        {"January", "Jan", 31, 1},
        {"February", "Feb", 30, 2},
        {"March", "Mar", 31, 3},
        {"April", "Apr", 30, 4},
        {"May", "May", 31, 5},
        {"June", "Jun", 30, 6},
        {"July", "Jul", 31, 7},
        {"August", "Aug", 30, 8},
        {"September", "Sep", 31, 9},
        {"October", "Oct", 30, 10},
        {"November", "Nov", 31, 11},
        {"December", "Dec", 30, 12}
};
bool Judge_Leap(int );
int calculate_total_days(struct exact_date * ps);
char * s_gets(char * string, int n); // 输入月份名 月份缩写 或者月份序号
void eat_line(void); // 处理多余的'\n'

int main(void)
{
    struct exact_date appoint;
    struct exact_date * ps = &appoint;
    int total_days;

    puts("This program will count the totals days before the day you entered.(q to quit)");
    puts("Please enter the year:");
    while (scanf("%d", &appoint.year) == 1)
    {
//        输入信息
        eat_line();
        puts("Please enter the month of the year(accept a month sequence and month name and month abbreviation):");
        s_gets(appoint.month, LEN);
        puts("Please enter the day of the month:");
        scanf("%d", &appoint.days);
        eat_line();
//        计算天数
        total_days = calculate_total_days(ps);
//        检查是否发生错误
        if (total_days)
            printf("The total days of the day is %d.\n", total_days);
        else
            printf("Your input the wrong month information, please check it.\n");
        puts("Please continue(q to quit)");
        puts("Please enter the year:");
    }
    puts("Bye~");
    
    return 0;
}
int calculate_total_days(struct exact_date * ps)
{
    bool is_leap; // 判断时候为闰年
    bool input_check = false; // 判断是否输入的月份是错误的
    int total_days = 0;
    int month;
    char * ptr;

    is_leap = Judge_Leap(ps->year);
    if (is_leap)
        year[1].days = 29;
    else
        year[1].days = 28;
//    计算该月前的天数
    for (month = 0; month < MONTH; ++month)
    {
        if (strcmp(ps->month, year[month].mouth_name) == 0 || strcmp(ps->month, year[month].mouth_abb) == 0 ||
        strtol(ps->month, &ptr, 10) == year[month].sequence)
        {
            input_check = true;
            break;
        }
        total_days += year[month].days;
    }
//    如果没有找到这个月份 那么返回0
    if (input_check)
    {
        total_days += ps->days;
        return total_days;
    } else
        return 0;
}
bool Judge_Leap(int year_number)
{
    bool result = false;

    if (year_number % 400 == 0)
        result = true;
    else if (year_number % 4 == 0 && year_number % 100 != 0)
        result = true;

    return result;
}
char * s_gets(char * string, int n)
{
    char * result;
    char * find;

    result = fgets(string, n, stdin);
    if (result)
    {
        find = strchr(string, '\n');
        if (find)
            * find = '\0';
        else
            eat_line();
    }

    return result;
}
void eat_line(void)
{
    while (getchar() != '\n')
        continue;
}