#include <stdio.h>
#define NAME "CHJ, INC."
#define ADDRESS "101 ZJ Plaza"
#define PLACES "ZJ, CA 94904"
#define WIDTH 40

void Star_bar(void);

int main(void)
{
    Star_bar();
    printf("%s\n", NAME);
    printf("%s\n", ADDRESS);
    printf("%s\n", PLACES);
    Star_bar();

    return 0;
}
void Star_bar(void)
{
    for (int i = 0; i <= WIDTH; ++i) {
        putchar('*');
    }putchar('\n');
}