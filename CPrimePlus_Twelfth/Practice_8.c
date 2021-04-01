#include <stdio.h>
#include <stdlib.h>

int * make_array(int element, int value);
void show_array(const int array [], int n);

int main(void)
{
    int * pa;
    int size;
    int value;

    printf("Enter the number of elements: ");
    while (scanf("%d", &size) == 1 && size > 0)
    {
        printf("Enter the initialization values: ");
        scanf("%d", &value);
        pa = make_array(size, value);
        if (pa)
        {
            show_array(pa, size);
            free(pa);
        }
        printf("Enter the number of elements (<1 to quit): ");
    }printf("Done.\n");

    return 0;
}
int * make_array(int element, int value)
{
    int * result;

    result = (int *)malloc(element * sizeof(int));
    for (int i = 0; i < element; ++i)
        result[i] = value;

    return result;
}
void show_array(const int array [], int n)
{
    for (int i = 0; i < n; ++i) {
        printf("%d ", array[i]);
        if ((i + 1) % 8 == 0)
            printf("\n");
    }printf("\n");
}