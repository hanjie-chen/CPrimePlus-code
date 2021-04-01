#include <stdio.h>

#define FUND_LEN 50

struct funds {
    char bank[FUND_LEN];
    double bank_fund;
    char save[FUND_LEN];
    double save_fund;
};

double sum(const struct funds array[], int n);

int main(void)
{
    struct funds jones[2] = {
            {
                "Garlic-Melon Bank",
                4032.27,
                "Lucky save and Loan",
                8543.94
            },
            {
                "Honest Jack's Bank",
                3620.88,
                "Party time savings",
                3802.91
            }
    };

    printf("The jones have total of %.2f.\n", sum(jones, 2));

    return 0;
}
double sum(const struct funds array[], int n)
{
    double total = 0;

    for (int i = 0; i < n; ++i)
        total += array[i].bank_fund + array[i].save_fund;

    return total;
}