#include <stdio.h>
#define SIZE 10
int sum(int ar[], int n);
int main(void)
{
    int marbles[SIZE] = {20, 10, 5, 39, 4, 16, 19, 26, 31, 20 };
    long int answer;

    answer = sum(marbles, SIZE);
    printf("The total number of marbles is %ld.\n", answer);
//    marbles是10个整形数的数组 每个整形数存储大小为4故结果为40
    printf("The size of marbles is %zd bytes.\n", sizeof(marbles));

    return 0;
}
int sum(int ar[], int n)
{
    int result = 0;

    for (int i = 0; i < n; ++i) {
        result += ar[i];
    }
//    ar是一个指针地址 系统为指针创建的大小为8
    printf("The size of ar is %zd bytes.\n", sizeof(ar));

    return result;
}