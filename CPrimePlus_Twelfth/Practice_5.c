#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void show_array(int array[], int n);
void select_sort_array(int array[], int n);

int main(void)
{
    int array[SIZE];

    srand((unsigned int) time(0));
    for (int i = 0;i < SIZE; ++i)
        array[i] = rand() % 10;
    puts("The preview array is here:");
    show_array(array, SIZE);
    select_sort_array(array, SIZE);
    puts("The array after select sort is here:");
    show_array(array, SIZE);

    return 0;
}
void show_array(int array[], int n)
{
    for (int i = 0; i < n; ++i) {
        printf("%d ", array[i]);
        if ((i + 1) % 20 == 0)
            printf("\n");
    }
}
void select_sort_array(int array[], int n)
{
    int temp;

    for (int top = 0; top < n - 1; ++top)
        for(int seek = top + 1; seek < n; ++seek)
            if (array[top] < array[seek])
            {
                temp = array[top];
                array[top] = array[seek];
                array[seek] = temp;
            }
}