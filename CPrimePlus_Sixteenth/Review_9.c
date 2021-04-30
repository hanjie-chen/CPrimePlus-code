#include <stdio.h>

#define PR_DATE

int main(void)
{
#ifdef PR_DATE
    printf("Now the marco PR_DATE is defined and the compile time is %s\n", __TIME__);
#else
    printf("So bad, the marco is not defined\n");
#endif
    return 0;
}