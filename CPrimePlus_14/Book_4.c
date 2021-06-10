#include <stdio.h>

#define SIZE 20

struct names {
    char first[SIZE];
    char last[SIZE];
};
struct guy {
    struct names handle;
    char favourite_food[SIZE];
    char job[SIZE];
    float income;
};

int main(void)
{
    struct guy fellow[2] = {
            {
                    {"Even", "Villard"},
                    "grilled salmon",
                    "personality coach",
                    68112.00
            },
            {
                {"Rodney", "Swillbelly"},
                "tripe",
                "tabloid editor",
                432400.00
            }
    };
    struct guy * him;

    printf("address #1: %p #2: %p\n", &fellow[0], &fellow[1]);
    him = &fellow[0];
    printf("address #1: %p #2: %p\n", him, him + 1);
    printf("him->income is $%.2f: (*him).income is %.2f\n", him->income, (*him).income);
    ++him;
    printf("him->favourite_food is %s: him->handle.last is %s\n", him->favourite_food, him->handle.last);

    return 0;
}