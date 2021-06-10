#include <stdio.h>

#define FUND_LEN 50

struct funds {
    char band[FUND_LEN];
    double bank_fund;
    char save[FUND_LEN];
    double save_fund;
};

double sum_function_1(double , double );
double sum_function_2(const struct funds *);
double sum_function_3(struct funds);

int main(void)
{
    struct funds stan = {
            "Garlic-Melon Bank",
            4023.27,
            "Lucky's Savings and Loan",
            8543.94
    };

    printf("Stan have total of %.2f\n", sum_function_1(stan.bank_fund, stan.save_fund));
    printf("Stan have total of %.2f\n", sum_function_2(&stan));
    printf("Stan have total of %.2f\n", sum_function_3(stan));

    return 0;
}
double sum_function_1(double x, double y)
{
    return (x + y);
}
double sum_function_2(const struct funds * money)
{
    return (money->save_fund + money->bank_fund);
}
double sum_function_3(struct funds money)
{
    return (money.bank_fund + money.save_fund);
}