#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ARRAY_LENGTH 10

void Choose_Lucky_Star(const int array[], int size, int stars_count);
void Init_Array(int array[], int size);

int main(void)
{
    int member_sequence[ARRAY_LENGTH];
    int people_number;

    Init_Array(member_sequence, ARRAY_LENGTH);
    puts("This program will choose some lucky number for rand");
    puts("Please enter how many lucky number you want:");
//    幸运人数不能超过总人数
    while (scanf("%d", &people_number) == 1 && people_number <= ARRAY_LENGTH)
    {
        Choose_Lucky_Star(member_sequence, ARRAY_LENGTH, people_number);
        puts("Try again(q to quit)");
    }
    puts("Bye~");

    return 0;
}
void Choose_Lucky_Star(const int array[], int size, int stars_count)
{
    int * array_record;             // 将一个大小相同的数组全部初始化为0
    int choose;                     // 随机数
    int current_count = 0;          // 记录目前已经选择的人数
    // 动态分配内存 使其变为一个全0的数组
    array_record = (int *)calloc(size, sizeof(int));
    srand((unsigned int) time(0));
    while (current_count < stars_count)
    {
        choose = rand() % size;
//        如果是未被选择过的则打印 如果选择过那么跳过
        if (!array_record[choose])
        {
            printf("The lucky number-%d is %d in sequence number is %d\n", current_count, array[choose], choose);
            array_record[choose] = 1;
            current_count++;
        }
    }
//    释放内存
    free(array_record);
}
void Init_Array(int array[], int size)
{
    for (int i = 0; i < size; ++i)
        array[i] = (i + 1) * i;
}