#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char * s_gets(char * string, int n);

enum spectrum {
    red,
    orange,
    green,
    yellow,
    blue,
    violet
};
const char * colors[] = {
        "red",
        "orange",
        "green",
        "yellow",
        "blue",
        "violet"
};

#define LEN 30

int main(void)
{
    char choice[LEN];
    enum spectrum color;
    bool color_is_found = false;

    puts("Please enter a color(empty line to quit)");
    while (s_gets(choice, LEN) && choice[0] != '\0')
    {
        for (color = red; color < violet; ++color)
        {
            if (strcmp(choice, colors[color]) == 0)
            {
                color_is_found = true;
                break;
            }
        }
        if (color_is_found)
        {
            switch (color) {
                case red: puts("Rose are red.");
                    break;
                case orange: puts("Poppies are orange.");
                    break;
                case yellow: puts("Sunflowers are yellow.");
                    break;
                case green: puts("Grass is green.");
                    break;
                case blue: puts("Bluebells are blue");
                    break;
                case violet: puts("Violets are violet.");
                    break;
            }
        } else
            printf("I do not know about the color %s.\n", choice);
        color_is_found = false;
        puts("Next color, empty line to quit.");
    }
    puts("Bye~");

    return 0;
}
char * s_gets(char * string, int n)
{
    char * result;
    char * find;

    result = fgets(string, n, stdin);
    if (result)
    {
        find = strchr(string, '\n');
        if (find)
            * find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return result;
}