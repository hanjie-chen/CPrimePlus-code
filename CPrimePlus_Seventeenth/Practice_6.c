#include <stdio.h>

#define SIZE 20

int In_array(const int array[], int size, int find);
void Value_Array(int * array, int size);
void Show_Array(int * array, int size);

int main(void)
{
    int array[SIZE];
    int number = 10;

    Value_Array(array, SIZE);
    Show_Array(array, SIZE);
    if (In_array(array, SIZE, number))
        printf("%d is in array\n", number);
    else
        printf("%d is not in array\n", number);

    return 0;
}
int In_array(const int array[], int size, int find)
{
    int top = size - 1;
    int bottom = 0;
    int middle;
    int flag = 0;

    while (top != bottom)
    {
        middle = (top + bottom) / 2;
        if (find > array[middle])
            bottom = middle+1;
        else if (find < array[middle])
            top = middle;
        else
            flag = 1;

        if (flag == 1)
            break;
    }

    return flag;
}
void Value_Array(int * array, int size)
{
    for (int i = 0; i < size; ++i)
        array[i] = i;
}
void Show_Array(int * array, int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);
    printf("\n");
}