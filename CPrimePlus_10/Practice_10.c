#include <stdio.h>

#define SIZE 4

void show_array(const int array[], int n);
void add_array(const int source1[], const int source2[], int target[], int n);

int main(void)
{
    int source1[SIZE] = {2, 4, 5, 8};
    int source2[SIZE] = {1, 0, 4, 6};
    int target[SIZE];

    show_array(source1, SIZE);
    show_array(source2, SIZE);
    add_array(source1, source2, target, SIZE);
    show_array(target, SIZE);

    return 0;
}
void add_array(const int source1[], const int source2[], int target[], int n)
{
    for (int i = 0; i < n; ++i) {
        target[i] = source1[i] + source2[i];
    }
}
void show_array(const int array[], int n)
{
    for (int i = 0; i < n; ++i) {
        printf("%d ", array[i]);
    }printf("\n");
}