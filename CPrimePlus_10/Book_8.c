#include <stdio.h>
#define SIZE 10
int sum_point(int * start, int * end);
int main(void)
{
    int marbles[SIZE] = {20, 10, 5, 39 ,4 ,16, 19 ,26, 31, 20};
    int answer;

    answer = sum_point(marbles, marbles + SIZE);
    printf("The total of marbles is %d.\n", answer);

    return 0;
}
int sum_point(int * start, int * end)
{
    int result = 0;

//    while (start < end)
//    {
//        result += *start;
//        start++;
//    }
//    while循环可以压缩成一行 使用后缀表达式的形式 先使用该值 然后在对该值进行递增
    while (start < end)
        result += *(start++);

    return result;
}