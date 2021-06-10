#include "stdio.h"
#include "ctype.h"
int main(void)
{
    char ch;

    printf("Give me a letter of the alphabet, and I will give ");
    printf("an animal name \nbegin with that letter.\n");
    printf("Please type in a letter; type # to end the act.\n");
    while ((ch = getchar()) != '#')
    {
        if (ch == '\n')
            continue;
//        如果没有break语句, 那么会执行匹配到的case到default的所有语句
        if (islower(ch))
        {
            switch (ch) {
                case 'a':
                    printf("argali, a wild sheep of Asia\n");
                    break;
                case 'b':
                    printf("babirusa, a wild pig of Malay\n");
                    break;
                case 'c':
                    printf("coati, racoonlike mammal\n");
                    break;
                default:
                    printf("That's a stumper\n");
            }
        } else{
            printf("I recognize only lowercase letter.\n");
        }
        printf("Please type another letter or a '#' to end\n");
    }
    printf("Bye~\n");

    return 0;
}