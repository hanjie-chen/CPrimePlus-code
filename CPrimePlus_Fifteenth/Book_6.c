#include <stdio.h>
#include <stdbool.h>
// 线的样式 -- 实线 点线 虚线
#define SOLID 0
#define DOTTED 1
#define DASHED 2
// 三原色
#define RED 4
#define GREEN 2
#define BLUE 1
// 混合色
#define BLACK 0
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)

const char * color[8] = {
        "black", "red", "green", "yellow", "blue", "magenta", "cyan", "white"
};

struct box_props {
    bool opaque : 1;
    unsigned int fill_color : 3;
    unsigned int : 4;
    bool show_border : 1;
    unsigned int border_color : 3;
    unsigned int border_style : 2;
    unsigned int : 2;
};

void show_settings(const struct box_props * pb);

int main(void)
{
    struct box_props box = {true, YELLOW, true, GREEN, DASHED};

    printf("Original settings:\n");
    show_settings(&box);

    box.opaque = false;
    box.fill_color = WHITE;
    box.border_color = MAGENTA;
    box.border_style = SOLID;
    printf("\nModified box settings:\n");
    show_settings(&box);

    return 0;
}
void show_settings(const struct box_props * pb)
{
    printf("Bos is %s", pb->opaque ? "opaque" : "transparent");
    printf("The fill color is %s.\n", color[pb->fill_color]);
    printf("Border %s\n", pb->show_border ? "shown" : "no shown");
    printf("The border color is %s\n", color[pb->border_color]);
    printf("The border style is ");
    switch (pb->border_style) {
        case SOLID: printf("solid.\n");break;
        case DOTTED: printf("dotted.\n");break;
        case DASHED: printf("dashed.\n");break;
        default: printf("unknown type.\n");break;
    }
}