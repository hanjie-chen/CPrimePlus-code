#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LEN 20
#define SEQUENCE 19

struct names {
    char first_name[LEN];
    char last_name[LEN];
};
struct player {
    struct names player_name; // 球员姓名
    int court_count; // 上场次数
    int hit_count; // 击中数
    int total_bases; // 走垒数
    int run_batted_in; // 打点
    float hit_rate; // 安打率
};

void Print_Team_Information(struct player *, int);
void calculate_hit_rate(struct player *);
void Read_data(struct player *, FILE *);
void Deal_Repeat_Player(struct player *, struct player *);

int main(void)
{
//    初始化结构数组和初始化数组相同 只需要初始化其中一项 其他便自动初始化为0
    struct player team[SEQUENCE] = {
            {{"", ""}, 0, 0, 0, 0, 0}
    };
    struct player temp;
    int player_sequence;
    FILE * fp;
    bool repeat_data = false; //  判断是否是重复数据

    if ((fp = fopen("data", "r")) == NULL)
    {
        fprintf(stderr, "Can't open the file data.\n");
        exit(EXIT_FAILURE);
    }
    rewind(fp); // 让文件定位到开始
    while (fscanf(fp, "%d", &player_sequence) == 1)
    {
//        通过安打率判断这个数据是否在之前的数据中出现过
        if (team[player_sequence].hit_rate != 0)
            repeat_data = true;
//        没有出现过则输入 出现过则合并两者的数据 可惜了struct不能使用+=运算符
        if (!repeat_data)
            Read_data(&team[player_sequence], fp);
        else
        {
//            将重复的数据读取到一个临时的数组中去
            Read_data(&temp, fp);
//            合并两者数据
            Deal_Repeat_Player(&team[player_sequence], &temp);
        }
//        每次输入都对数据计算安打率
        calculate_hit_rate(&team[player_sequence]);
    }

    Print_Team_Information(team, SEQUENCE);

    return 0;
}
void Print_Team_Information(struct player * ps, int n)
{
    for (int i = 0; i < n; ++i) {
        fprintf(stdout, "%2d %10s %10s %2d %2d %2d %2d %2.2f\n", i, ps[i].player_name.last_name, ps[i].player_name.first_name,
                ps[i].court_count, ps[i].hit_count, ps[i].total_bases, ps[i].run_batted_in, ps[i].hit_rate);
    }
}
void calculate_hit_rate(struct player * ps)
{
        ps->hit_rate = ((float)ps->hit_count) / ((float)ps->court_count);
}
void Read_data(struct player * ps, FILE * fp)
{
    fscanf(fp, "%s %s %d %d %d %d", ps->player_name.last_name, ps->player_name.first_name,
           &ps->court_count, &ps->hit_count, &ps->total_bases,
           &ps->run_batted_in);
}
void Deal_Repeat_Player(struct player * ps_main, struct player * ps_branch)
{
    ps_main->court_count += ps_branch->court_count;
    ps_main->hit_count += ps_branch->hit_count;
    ps_main->total_bases += ps_branch->total_bases;
    ps_main->run_batted_in += ps_branch->run_batted_in;
}