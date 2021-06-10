#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LEN 20
#define MONTH 12

struct month_info{
    char mouth_name[20];
    char mouth_abb[4];
    int days;
    int sequence;
};
// 初始化该结构数组
const struct month_info year[MONTH] = {
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
char * s_gets(char * string, int n);

int main(void)
{
    char mouth_name[LEN];
    int total_days = 0;

    puts("Please enter the mouth name and this program will return the total days before the mouth in this year:");
    puts("Please [enter] a new line to quit");
    while (s_gets(mouth_name, LEN) && mouth_name[0] != '\0')
    {
        bool flag = false;
        for (int i = 0; i < MONTH; ++i)
            if (strcmp(mouth_name, year[i].mouth_name) == 0 || strcmp(mouth_name, year[i].mouth_abb) == 0)
            {
                total_days = calculate_days(i + 1);
                flag = true;
                break;
            }
        if (flag)
            printf("The total days before the mouth in this year is %d.\n", total_days);
        else
            printf("You have to enter the full mouth name or abbreviation mouth name.\n");
        printf("Please try another mouth\n");
        puts("Please [enter] a new line to quit");
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
            while (getchar() != '\n')
                continue;
    }

    return result;
}