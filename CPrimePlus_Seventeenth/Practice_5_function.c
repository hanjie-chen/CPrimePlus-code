#include "Practice_5.h"
#include <stdio.h>
#include <stdlib.h>

void InitializeStack(Stack * point_stack)
{
    point_stack->item_count = 0;
    point_stack->top = NULL;
}
bool StackIsEmpty(const Stack * point_stack)
{
    return (point_stack->item_count == 0) ? true : false;
}
bool StackIsFull(const Stack * point_stack)
{
    return (point_stack->item_count == STACK_MAX) ? true : false;
}
int StackItemCount(const Stack * point_stack)
{
    return point_stack->item_count;
}
bool PushStackNode(Stack * point_stack, Item * point_item)
{
    if (StackIsFull(point_stack))
        return false;
    Node * temp;
//    初始化节点数据
    temp = (Node *) malloc(sizeof(Node));
    temp->next = NULL;
    temp->item = *point_item;
//    如果为栈为空则头指针指向该区域
    if (StackIsEmpty(point_stack))
        point_stack->top = temp;
    else
    {
        temp->next = point_stack->top;
        point_stack->top = temp;
    }
    point_stack->item_count++;

    return true;
}
bool PopStackNode(Stack * point_stack, Item * item)
{
    if (StackIsEmpty(point_stack))
        return false;
    Node * temp;
//    将这个节点的值带出函数
    *item = point_stack->top->item;
//    销毁该节点，释放该节点占用的内存
    temp = point_stack->top;
    point_stack->top = point_stack->top->next;
    point_stack->item_count--;
    free(temp);

    return true;
}
void Traverse(Stack * point_stack, void (* function)(Item item))
{
    Node * temp = point_stack->top;

    while (temp != NULL)
    {
        function(temp->item);
        temp=temp->next;
    }
}
bool InStack(Stack * point_stack, Item * item)
{
    Node * temp = point_stack->top;

    while (temp != NULL)
    {
        if ((temp->item).ch == (*item).ch)
            return true;
        temp=temp->next;
    }

    return false;
}
void DeleteAllNode(Stack * point_stack)
{
    Item item;

    while (point_stack->top != NULL)
    {
        PopStackNode(point_stack, &item);
        point_stack->top = point_stack->top->next;
    }
}