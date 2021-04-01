#include <stdio.h>
#include <stdlib.h>

struct flex {
    int count;
    double average;
    double scores[];// 伸缩性数组成员 必须放一位
};

void showFlex(struct flex * p);

int main(void)
{
    struct flex * pf;
    int n = 5;
    double total = 0;

//    请求为一个结构和一个数组动态分配内存
    pf = (struct flex *)malloc(sizeof(struct flex) + n * sizeof(double));
    pf->count = n;
    for (int i = 0; i < n; ++i) {
        pf->scores[i] = 20.0 - i;
        total += pf->scores[i];
    }
    pf->average = total / pf->count;
    showFlex(pf);

    return 0;
}
void showFlex(struct flex * p)
{
    printf("Scores : ");
    for (int i = 0; i < p->count; ++i)
        printf("%g ", p->scores[i]);
    printf("\nAverage: %g\n", p->average);

}