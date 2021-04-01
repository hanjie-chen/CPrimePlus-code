#include <stdio.h>
#define MONTHS 12
#define YEARS 5
int main(void)
{
//    初始化二维数组
    const float rain[YEARS][MONTHS] = {
            { 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
            { 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
            { 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
            { 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
            { 7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2},
    };
    int year, month;
    float sub_total, total;
//    把指针p指向rain的首地址 相当于&rain[0][0]
    const float (* p)[MONTHS];
    p = rain;

    printf(" YEAR     RAINFALL(inches)\n");
    for (year = 0, total = 0; year < YEARS; ++year) {
        for (month = 0, sub_total = 0; month < MONTHS; ++month) {
            sub_total += *(*(p + year) + month);
        }
        printf("%5d %12.1f\n", 2010+year, sub_total);
        total += sub_total;
    }
    printf("\n The year average is %.1f inches.\n\n", total / YEARS);
    printf(" MONTHLY AVERAGE:\n\n");
    printf(" Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec.\n");
    for (month = 0;  month< MONTHS; ++month) {
        for (year = 0, sub_total = 0;  year< YEARS; ++year) {
            sub_total += *(*(p + year) + month);
        }
        printf("%4.1f ", sub_total / YEARS);
    }


    return 0;
}