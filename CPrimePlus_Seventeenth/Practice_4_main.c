#include "Practice_4.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_PER_HOUR 60
#define STARS "******************************************************************"

bool new_customer(double number); // 是否有新顾客到来
bool choice_booth(); // 选择店铺
Item set_customer(long when);  // 设置顾客参数
static void eat_line(void);
Item Choice_Line(Queue * line, long int * refused_customer, long int * customers, long int cycle); //
void Print_Simulation_Result(long int customers, long int served_customers, long int refused_customers, long cycle_limits
                             ,long int sum_line, long int line_wait); //
void Deal_With_Customers(Queue  * line, int * wait_time, long int * line_wait, Item * temp, long int * served_customers,
                         long int * sum_line, long int cycle); // 对其进行计数
void End_Simulation(Queue * line1, Queue * line2); // 释放所有动态申请的内存

int main(void)
{
    Queue line1, line2;                                             // 队列
    Item temp1, temp2;                                              // 新的顾客
    int hours;                                                      // 模拟的时间长度
    int average_customers_per_hour;                                 // 每小时的平均顾客
    long cycle_limits;                                              // 循环大小限制
    long refused_customers1 = 0, refused_customers2 = 0;            // 队列1拒绝的顾客 队列2拒绝的顾客
    long served_customers1 = 0, served_customers2 = 0;              // 队列1服务过的顾客 队列2服务过的顾客
    long customers1 = 0, customers2 = 0;                            // 加入队列的顾客数量
    long sum_line1 = 0, sum_line2 = 0;                              // 队列长度的总和
    int wait_time1 = 0, wait_time2 = 0;                             // 当前正在咨询的顾客花费的时间
    double min_per_customers;                                       // 平均每位顾客的到来时间
    long line_wait1 = 0, line_wait2 = 0;                            // 队列累计等待时间

//    初始化队列——2个摊位
    InitializeQueue(&line1);
    InitializeQueue(&line2);

    srand((unsigned int) time(0)); // 随机初始化rand()
    puts("Sigmund Lander's Advice Booth And the Chen Han Jie Recognize Booth");
    puts("Enter the number of the simulation hours:"); // 输入两个摊位一天工作的时间 个人感觉工作时间应该是一样的
    scanf("%d", &hours);
    eat_line();
    cycle_limits = hours * MIN_PER_HOUR; // 计算循环次数
    puts("Enter the average number of customers per hour:");
    scanf("%d", &average_customers_per_hour);
    eat_line();
    min_per_customers = (double )MIN_PER_HOUR / average_customers_per_hour;

    for (long int cycle = 0; cycle < cycle_limits; ++cycle) {
//        随机给两个摊位添加顾客
        if (new_customer(min_per_customers))
        {
            if (choice_booth())
                temp1 = Choice_Line(&line1, &refused_customers1, &customers1, cycle);
            else
                temp2 = Choice_Line(&line2, &refused_customers2, &customers2, cycle);
        }
        Deal_With_Customers(&line1, &wait_time1, &line_wait1, &temp1, &served_customers1, &sum_line1, cycle);
        Deal_With_Customers(&line2, &wait_time2, &line_wait2, &temp2, &served_customers2, &sum_line2, cycle);
    }
    puts("Here is the line 1: Sigmund Lander's Advice Booth");
    Print_Simulation_Result(customers1, served_customers1, refused_customers1, cycle_limits, sum_line1, line_wait1);
    puts(STARS);
    puts("Here is the line 2: Chen Han Jie Recognize Booth");
    Print_Simulation_Result(customers2, served_customers2, refused_customers2, cycle_limits, sum_line2, line_wait2);
    End_Simulation(&line1, &line2);
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
bool choice_booth()
{
    if (rand() % 2 == 1)
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
Item Choice_Line(Queue * line, long int * refused_customer, long int * customers, long int cycle)
{
    Item temp;

    if (QueueIsFull(line))
        (*refused_customer)++;
    else {
        (*customers)++;
        temp = set_customer(cycle);
        AddQueueItem(temp, line);
    }

    return temp;
}
void Deal_With_Customers(Queue  * line, int * wait_time, long int * line_wait, Item * temp, long int * served_customers,
                         long int * sum_line, long int cycle)
{
    if (*wait_time <= 0 && !QueueIsEmpty(line))
    {
        DeleteQueueItem(temp, line);
        *wait_time = temp->process_time;
        *line_wait += cycle - temp->arrive_time;
        (*served_customers)++;
    }
    if (*wait_time > 0)
        (*wait_time)--;

    *sum_line += QueueItemCount(line);
}
void Print_Simulation_Result(long int customers, long int served_customers, long int refused_customers, long cycle_limits,
                             long int sum_line, long int line_wait)
{
    if (customers > 0)
    {
        printf("customers accepted : %ld\n", customers);
        printf("  customers served : %ld\n", served_customers);
        printf(" refused customers : %ld\n", refused_customers);
        printf("average queue size : %.2f\n", (double )sum_line / (double )cycle_limits);
        printf(" average wait time : %.2f minutes\n", (double )line_wait / (double )served_customers);
    }
    else
        printf("This line have no customers!");
}
void End_Simulation(Queue * line1, Queue * line2)
{
    EmptyTheQueue(line1);
    EmptyTheQueue(line2);
}