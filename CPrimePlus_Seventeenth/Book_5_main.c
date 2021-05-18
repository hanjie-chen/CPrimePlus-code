#include "Book_5.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_PER_HOUR 60

bool new_customer(double number); // 是否有新顾客到来
Item set_customer(long when);  // 设置顾客参数
static void eat_line(void);

int main(void)
{
    Queue line;                             // 队列
    Item temp;                              // 新的顾客
    int hours;                              // 模拟的时间长度
    int average_customers_per_hour;         // 每小时的平均顾客
    long cycle_limits;                      // 循环大小限制
    long refused_customers = 0;             // 拒绝的顾客
    long served_customers = 0;              // 服务过的顾客
    long customers = 0;                     // 加入队列的顾客数量
    long sum_line = 0;                      // 队列长度的总和
    int wait_time = 0;                      // 当前正在咨询的顾客花费的时间
    double min_per_customers;               // 平均每位顾客的到来时间
    long line_wait = 0;                     // 队列累计等待时间


    InitializeQueue(&line);
    srand((unsigned int) time(0)); // 随机初始化rand()
    puts("Case Study: Sigmund Lander's Advice Booth");
    puts("Enter the number of the simulation hours:");
    scanf("%d", &hours);
    eat_line();
    cycle_limits = hours * MIN_PER_HOUR;
    puts("Enter the average number of customers per hrour:");
    scanf("%d", &average_customers_per_hour);
    eat_line();
    min_per_customers = (double )MIN_PER_HOUR / average_customers_per_hour;

    for (long int cycle = 0; cycle < cycle_limits; ++cycle) {
        if (new_customer(min_per_customers))
        {
//            如果队列已满则拒绝顾客 如果队列没有满则加入顾客
            if (QueueIsFull(&line))
                refused_customers++;
            else{
                customers++;
                temp = set_customer(cycle);
                AddQueueItem(temp, &line);
            }
        }
        if (wait_time <= 0 && !QueueIsEmpty(&line))
        {
            DeleteQueueItem(&temp, &line);
            wait_time = temp.process_time;
            line_wait += cycle - temp.arrive_time;
            served_customers++;
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += QueueItemCount(&line);
    }
    if (customers > 0)
    {
        printf("customers accepted : %ld\n", customers);
        printf("  customers served : %ld\n", served_customers);
        printf(" refused customers : %ld\n", refused_customers);
        printf("average queue size : %.2f\n", (double )sum_line / (double )cycle_limits);
        printf(" average wait time : %.2f minutes\n", (double )line_wait / (double )served_customers);
    }else{
        puts("No customers!");
    }
    EmptyTheQueue(&line);
    puts("Everything is finished.Bye~");

    return 0;
}
bool new_customer(double number)
{
    if (rand() * number / RAND_MAX < 1)
        return true;
    else
        return false;
}
Item set_customer(long when)
{
    Item temp;

    temp.arrive_time = when;
    temp.process_time = rand() % 3 + 1;

    return temp;
}
inline static void eat_line(void)
{
    while (getchar() != '\n')
        continue;
}