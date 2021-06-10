/* 对程序改进的思考：
 * 这个程序看似好像运行的不错，但是前提是输入的数据是规定的数字，而不是随便输入的
 * 我尝试着看看能不能对随便输入的结果能不能进行提示，但是失败了
 * 光光对输入选择字母的修改，输入函数的原理是存在一个输入队列，但是我输入了一个字母和一个回车（换行符）， 所以在进行while循环的时候，getchar（）
 * 自动把换行符进行填充，导致不能进行提醒
 * 2020/9/28 陈翰杰
 * */
#include "stdio.h"
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
    char choice_vegetable_letter;
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
        choice_vegetable_letter = getchar();
        if (choice_vegetable_letter == 'q')
            break;
        switch (choice_vegetable_letter) {
            case 'a':
                printf("Please enter how much pounds the Artichoke you want:");
                scanf("%f", &choice_artichoke_weight);
                total_artichoke_weight += choice_artichoke_weight;
                break;
            case 'b':
                printf("Please enter how much pounds the Beet you want:");
                scanf("%f", &choice_beet_weight);
                total_beet_weight += choice_beet_weight;
                break;
            case 'c':
                printf("Please enter how much pounds the Carrot you want:");
                scanf("%f", &choice_carrot_weight);
                total_carrot_weight += choice_carrot_weight;
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
    printf("Welcome to ABC General Store! Here is menu, Please enter the letter to choose vegetables\n");
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
