#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char * argv[])
{
    double base_number;
    long int index_number;
    double result;
    char * end_ptr;

    base_number = strtod(argv[1], &end_ptr);
    printf("The string is %s and the transfer number is %lf\n", argv[1], base_number);
    index_number = strtol(argv[2], &end_ptr, 10);
    printf("The string is %s and the long int number is %ld\n", argv[2], index_number);
    result = pow(base_number, index_number);
    printf("The result is %lf\n", result);

    return 0;
}