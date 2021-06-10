#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    double number;
    double total = 0;
    unsigned int count = 0;

    fputs("Please enter numbers (q to quit)", stdout);
    while (scanf("%lf", &number) == 1)
    {
        count++;
        total += number;
        fputs("Please enter numbers (q to quit): ", stdout);
    }
    if (argc == 1)
        fprintf(stdout, "You have enter %u numbers and there average is %f\n", count, (double) (total / count));
    else if (argc == 2)
    {
        FILE * fp;
        if ((fp = fopen(argv[1], "w")) == NULL)
        {
            fprintf(stderr, "Error in opening file %s\n", argv[1]);
            exit(EXIT_FAILURE);
        }
        fprintf(fp, "You have enter %u numbers and there average is %f\n", count, (double) (total / count));
        if (fclose(fp) != 0)
            fprintf(stderr, "Error in closing file %s\n", argv[1]);
    } else
    {
        fputs("Please enter no argument or one argument.", stderr);
        exit(EXIT_FAILURE);
    }
    fputs("Done. Bye~", stdout);

    return 0;
}