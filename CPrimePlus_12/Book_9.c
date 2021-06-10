#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double * ptd;
    int max;
    int number;
    int i = 0;

    puts("What is the maximum number of the type double entries.");
    if (scanf("%d", &max) != 1)
    {
        puts("Number not correctly entered -- bye.");
        exit(EXIT_FAILURE);
    }
//    分配内存 并且把ptd指针指向第一个单元
    ptd = (double *) malloc(max * sizeof(double));
//    如果内存分配失败
    if (ptd == NULL)
    {
        puts("Memory allocated failed. Goodbye.");
        exit(EXIT_FAILURE);
    }
//    输入每一个单元的值
    puts("Please enter the values: (q to quit)");
    while (i < max && scanf("%lf", &ptd[i]) == 1)
        ++i;
    printf("Here are your %d entries:\n", number = i);
    for (i = 0; i < number; ++i) {
        printf("%7.2f ", ptd[i]);
        if (i % 7 == 6)
            putchar('\n');
    }
    if (i % 7 != 0)
        putchar('\n');
    puts("Done.");
    free(ptd);

    return 0;
}