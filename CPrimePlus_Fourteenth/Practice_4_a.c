#include <stdio.h>
#include <string.h>

#define NAME_LEN 20
#define PEOPLE_NUMBER 5
// 创建两个结构
struct name {
    char first_name[NAME_LEN];
    char middle_name[NAME_LEN];
    char last_name[NAME_LEN];
};
struct society_people {
    char society_id[10];
    struct name society_name;
};

void Print_People_Information(struct society_people *, int n);

int main(void)
{
    struct society_people people[PEOPLE_NUMBER] = {
            {"302039823", {"Dribble", "Me", "Flossie"}},
            {"302039824", {"Bill", "", "Flossie"}},
            {"302039825", {"Mark", "", "Flossie"}},
            {"302039826", {"John", "", "Flossie"}},
            {"302039827", {"Jack", "Me", "Flossie"}},
    };

    Print_People_Information(people, PEOPLE_NUMBER);

    return 0;
}
void Print_People_Information(struct society_people * ps, int n)
{
    for (int i = 0; i < n; ++i) {
        if (strlen(ps->society_name.middle_name))
            printf("%s, %s %c.-%s\n",ps->society_name.first_name, ps->society_name.last_name, ps->society_name.middle_name[0], ps->society_id);
        else
            printf("%s, %s--%s\n",ps->society_name.first_name, ps->society_name.last_name, ps->society_id);
        ps++;
    }

}