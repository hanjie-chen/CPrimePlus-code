#include <stdio.h>

#define MAX_TITLE_LEN 41
#define MAX_AUTHOR_LEN 31

struct book {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    float value;
};

int main(void)
{
    struct book read_first;
    int score;

    printf("Enter test score:");
    scanf("%d", &score);
    if (score >= 84)
        read_first = (struct book){
        "Crime and Punishment",
        "Fyodor Dostoyvsky",
        11.25
    };
    else
        read_first = (struct book){
        "Mr. Bouncy's Nice Hat",
        "Fred Winsome",
        5.99
    };
    printf("You assigned reading:\n");
    printf("%s by %s ($%.2f)\n", read_first.title, read_first.author, read_first.value);
    
    return 0;
}