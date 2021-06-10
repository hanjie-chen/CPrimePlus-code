#include "stdio.h"
int main(void)
{
    float single_interest = 100.0;
    float compound_interest = 100.0;
    int year;

    for (year = 1; compound_interest <= single_interest; ++year) {
        single_interest += 100.0 * 0.1;
        compound_interest += compound_interest * 0.05;
    }
    printf("在第%d年的时候，复合利息会超过单利息，此时符合利息总投资额：%f,单利息总投资额：%f\n", year - 1, compound_interest,single_interest);

    return 0;
}