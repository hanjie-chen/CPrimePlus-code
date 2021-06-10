#include <stdio.h>

int critic(int units);

int main(void)
{
    int units;

    printf("How many pounds to a firkin of butter\n");
    scanf("%d", &units);
    while (critic(units))
        scanf("%d", &units);
    printf("You must have looked it up!\n");

    return 0;
}
int critic(int units)
{
    if (units == 56)
        return 0;
    else
    {
        printf("Not lucky, my friends.Try again.\n");
        return 1;
    }
}