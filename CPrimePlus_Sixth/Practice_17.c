#include "stdio.h"
int main(void)
{
    float all_money = 100.0;
    int year;

    for (year = 1; all_money >= 0; ++year) {
        all_money += all_money * 0.08;
        all_money -= 10.0;
    }
    printf("在%d年后会去完钱", year - 1);
    return 0;
}