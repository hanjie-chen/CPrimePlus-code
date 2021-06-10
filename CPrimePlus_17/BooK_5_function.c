#include "Book_5.h"
#include <stdio.h>
#include <stdlib.h>

// 使用static 是为了只让该文件看得见这个函数 这个函数只服务于本文件是其中某个函数的配套函数
// 如果以后更改了Node的结构内容 那么只需要修改该函数即可 不用修改其他调用该函数的函数
static void CopyToNode(Node * temp, Item item);
static void CopyToItem(Node * temp, Item * item);

void InitializeQueue(Queue * point_queue)
{
//    设置头尾指针指向NULL
    point_queue->last_node = NULL;
    point_queue->head_node = NULL;
    point_queue->node_count = 0;
}

bool QueueIsFull(const Queue * point_queue)
{
//    如果最队列中的项数和最大值相同 认为队列已满
    return point_queue->node_count == MAX_QUEUE;
}

bool QueueIsEmpty(const Queue * point_queue)
{
//    如果队列中一项都没有认定为空
    return point_queue->node_count == 0;
}

int QueueItemCount(const Queue * point_queue)
{
    return (int)(point_queue->node_count);
}

bool AddQueueItem(Item item, Queue * point_queue)
{
//    如果队列已满
    if (QueueIsFull(point_queue))
    {
        fputs("The queue is full, can not add node!", stderr);
        return false;
    }
    Node * temp;
//    申请内存用于添加节点
    temp = (Node *) malloc(sizeof(Node));
//    如果申请节点失败直接退出程序
    if (temp == NULL)
    {
        fputs("Can not allocate memory !", stderr);
        exit(1);
    }
//    设置该节点内容
    CopyToNode(temp, item);
    temp->next = NULL;
//    如果队列为空则队列的头指针也指向temp 如果不为空则队列中原最后一项的指针的下一项为temp
    if (QueueIsEmpty(point_queue))
        point_queue->head_node = temp;
    else
        point_queue->last_node->next = temp;
//    设置队列中的最后一项为temp
    point_queue->last_node = temp;
//    队列节点+1
    point_queue->node_count++;

    return true;
}

bool DeleteQueueItem(Item * point_item, Queue * point_queue)
{
//    首先检查队列是否为空
    if (QueueIsEmpty(point_queue))
    {
        fputs("The queue is empty please add first then delete", stderr);
        return false;
    }
    Node * delete;
//    把要删除的item内容通过指针保存到另外一个地址
    CopyToItem(point_queue->head_node, point_item);
//    保存该需要删除的地址
    delete = point_queue->head_node;
//    如果队列只有一项则把头尾指针置NULL 如果不知一项则头指针指向下一项
    if (point_queue->head_node->next == NULL)
        point_queue->head_node = point_queue->last_node = NULL;
    else
        point_queue->head_node = point_queue->head_node->next;
//    设置成员-1
    point_queue->node_count--;
//    释放该地址的内存空间 彻底删除该成员
    free(delete);

    return true;
}

void EmptyTheQueue(Queue * point_queue)
{
    if (QueueIsEmpty(point_queue))
        fputs("The queue is empty no need to empty again!\n", stderr);
    else {
        Item temp;
//        调用delete函数逐个删除队列元素
        while (point_queue->node_count != 0)
            DeleteQueueItem(&temp, point_queue);
    }
}

static void CopyToNode(Node * temp, Item item)
{
    temp->item = item;
}
static void CopyToItem(Node * temp, Item * item)
{
    *item = temp->item;
}