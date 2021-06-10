/* 这个程序使用字符串数组解决了其中一个输入队列的问题
 * 但是在switch中还是存在一个数输入队列自动填充的问题
 * 2020/9/30 陈翰杰
 * */
#include "stdio.h"
#include "string.h"
#define ARTICHOKE_PER_POUND 2.05
#define BEET_PER_POUND 1.15
#define CARROT_PER_POUND 1.09
#define DISCOUNT 0.05
#define PACKAGE_MONEY_FIRST 6.5
#define PACKAGE_MONEY_SECOND 14
#define PACKAGE_MONEY_THIRD_PER_POUND 0.5
void Menu_Print(void);
float Calculate_Freight(float total_vegetable_weight);
float Calculate_Total_Money(float total_artichoke_money, float total_beet_money, float total_carrot_money);
void Calculate_And_Print_Result(float total_artichoke_weight, float total_beet_weight, float total_carrot_weight);
int main(void)
{
//    选择蔬菜字母
    char choice_vegetable_letter[10];
//    每次输入的蔬菜的重量
    float choice_artichoke_weight;
    float choice_beet_weight;
    float choice_carrot_weight;
//    计算每种蔬菜的总重量
    float total_artichoke_weight = 0;
    float total_beet_weight = 0;
    float total_carrot_weight = 0;

//    打印选择菜单
    Menu_Print();
//    循环输入蔬菜的重量, 求出每种蔬菜的总重量
    while (1) {
        scanf("%s", choice_vegetable_letter);
//        把if语句都放到一个里面去，不然逻辑上虽然通，但是程序上不好看
        if (strlen(choice_vegetable_letter) > 1)
        {
            printf("Please only enter a letter, not more than one.\n");
            continue;
        }
        else if (choice_vegetable_letter[0] == 'q')
            break;
        else if (!(choice_vegetable_letter[0] >= 'a' && choice_vegetable_letter[0] <= 'c'))
        {
            printf("Please use the right letter.\n");
            continue;
        }

//        这个地方还是有输入队列自动填充的问题
        switch (choice_vegetable_letter[0]) {
            case 'a':
                printf("Please enter how much pounds the Artichoke you want:");
                if (scanf("%f", &choice_artichoke_weight) == 1)
                    total_artichoke_weight += choice_artichoke_weight;
                else
                    printf("Please enter number not another things.\n");
                break;
            case 'b':
                printf("Please enter how much pounds the Beet you want:");
                if (scanf("%f", &choice_beet_weight) == 1)
                    total_beet_weight += choice_beet_weight;
                else
                    printf("Please enter number not another things.\n");
                break;
            case 'c':
                printf("Please enter how much pounds the Carrot you want:");
                if (scanf("%f", &choice_carrot_weight) == 1)
                    total_carrot_weight += choice_carrot_weight;
                else
                    printf("Please enter number not another things.\n");
                break;
            default:
                break;
        }
    }
//    计算并且输出三种蔬菜重量和费用, 蔬菜总费用, 运费, 和两者合计费用
    Calculate_And_Print_Result(total_artichoke_weight, total_beet_weight, total_carrot_weight);

    return 0;
}
void Menu_Print(void)
{
    printf("Welcome to ABC General Store! Here is menu, Please enter only a  letter to choose vegetables\n");
    printf("********************************\n");
    printf("a:Artichoke               b:Beet\n");
    printf("c:Carrot                  q:quit\n");
    printf("********************************\n");
}
float Calculate_Total_Money(float total_artichoke_money, float total_beet_money, float total_carrot_money)
{
    float result;

    result =  total_artichoke_money + total_beet_money + total_carrot_money;
    if (result >= 100)
        result -= result * DISCOUNT;
    else
        ;

    return result;
}
float Calculate_Freight(float total_vegetable_weight)
{
    if (total_vegetable_weight <= 5)
        return PACKAGE_MONEY_FIRST;
    else if (total_vegetable_weight >5 && total_vegetable_weight <=20)
        return PACKAGE_MONEY_SECOND;
    else
        return (total_vegetable_weight - 20) * PACKAGE_MONEY_THIRD_PER_POUND + PACKAGE_MONEY_SECOND;
}
void Calculate_And_Print_Result(float total_artichoke_weight, float total_beet_weight, float total_carrot_weight)
{
//    计算每种蔬菜的总费用
    float total_artichoke_money;
    float total_beet_money;
    float total_carrot_money;
//    计算所有蔬菜的总重量 总费用 总运费
    float total_vegetables_weight;
    float total_vegetable_money;
    float freight;

//    计算每种蔬菜费用和总费用
    total_artichoke_money = total_artichoke_weight * ARTICHOKE_PER_POUND;
    total_beet_money = total_beet_weight * BEET_PER_POUND;
    total_carrot_money = total_carrot_weight * CARROT_PER_POUND;
    total_vegetables_weight = total_artichoke_weight + total_beet_weight + total_carrot_weight;
    total_vegetable_money = Calculate_Total_Money(total_artichoke_money, total_beet_money, total_carrot_money);
    freight = Calculate_Freight(total_vegetables_weight);
//    打印出各种数据
    printf("Your total artichoke is %.2f pounds which you have to pay %.2f$\n", total_artichoke_weight, total_artichoke_money);
    printf("Your total beet is %.2f pounds which you have to pay %.2f$\n", total_beet_weight, total_beet_money);
    printf("Your total carrot is %.2f pounds which you have to pay %.2f$\n", total_carrot_weight, total_carrot_money);
//    printf("%.2f$.\n", freight);
    printf("The total weight is %.2f, and it will cast you %.2f$ and %.2f$ freight, the total is %.2f$.\n",
           total_vegetables_weight, total_vegetable_money, freight, freight + total_vegetable_money);

}
