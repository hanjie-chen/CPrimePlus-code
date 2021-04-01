#include <stdio.h>

struct month_info{
    char mouth_name[20];
    char mouth_abb[4];
    int days;
    int sequence;
};
// 初始化该结构数组
const struct month_info year[12] = {
        {"January", "Jan", 31, 1},
        {"February", "Feb", 28, 2},
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
int calculate_days(int mouth);

int main(void)
{
    int mouth;
    int total_days;

    puts("Please enter the mouth number and this program will return the total days before the mouth in this year:");
    while (scanf("%d", &mouth) == 1 && mouth <= 12)
    {
        total_days = calculate_days(mouth);
        printf("The total days before the mouth in this year is %d\n", total_days);
        puts("Please enter the mouth number(q to quit)");
    }
    puts("Bye~");

    return 0;
}
int calculate_days(int mouth)
{
    int total_days = 0;

    for (int i = 0; i < mouth; ++i)
        total_days += year[i].days;

    return total_days;
}