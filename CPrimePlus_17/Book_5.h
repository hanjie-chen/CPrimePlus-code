#ifndef CPRIMEPLUS_SEVENTEENTH_BOOK_4_H
#define CPRIMEPLUS_SEVENTEENTH_BOOK_4_H

#include <stdbool.h>

/* 这里是一些类型的定义 */
#define MAX_QUEUE 10

typedef struct {
    long int arrive_time; // 顾客加入队列的时间点
    int process_time;     // 顾客询问的时间
} Item;

typedef struct node {
    Item item;
    struct node * next;
} Node;

typedef struct {
    Node * head_node;           // 指向头结点
    Node * last_node;           // 指向尾节点
    unsigned int node_count;    // 节点个数
} Queue;
/* 这里防止函数申明 */

// 操作       初始化队列
// 前置条件    point_queue指向一个队列
// 后置条件    队列被初始化为空
void InitializeQueue(Queue * point_queue);

// 操作       判断队列是否已满
// 前置条件    point_queue指向一个初始化后的队列
// 后置条件    如果队列已满则返回true 否则返回false
bool QueueIsFull(const Queue * point_queue);

// 操作       判断队列是否为空
// 前置条件    point_queue指向一个初始化之后的队列
// 后置条件    如果队列空则返回true 否则返回false
bool QueueIsEmpty(const Queue * point_queue);

// 操作       统计队列中项目的数量
// 前置条件    point_queue指向一个初始化之后的队列
// 后置条件    返回队列中的项数
int QueueItemCount(const Queue * point_queue);

// 操作       在队列末尾添加项
// 前置条件    point_queue指向一个初始化之后的队列
// 后置条件    队列末尾添加了一项 成功返回true 失败返回false
bool AddQueueItem(Item item, Queue * point_queue);

// 操作       删除队列中第一项
// 前置条件    point_queue指向一个初始化之后的队列
// 后置条件    删除队列中的第一项 把删除的项赋值给point_item指向的指针 删除成功返回true 失败返回false
bool DeleteQueueItem(Item * point_item, Queue * point_queue);

// 操作       清空队列
// 前置条件    point_queue指向一个被初始化过的队列
// 后置条件    队列使用的所有内存被释放
void EmptyTheQueue(Queue * point_queue);

#endif //CPRIMEPLUS_SEVENTEENTH_BOOK_4_H
