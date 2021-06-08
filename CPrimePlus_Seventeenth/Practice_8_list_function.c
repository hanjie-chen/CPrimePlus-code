#include "Practice_8_list.h"
#include <stdio.h>
#include <stdlib.h>

//      设置链表为空
void InitializeList(List * plist)
{
    plist->head = plist->end = NULL;
}
//      判断链表是否为空
bool ListIsEmpty(const List * plist)
{
    return (plist->head == NULL) ? true : false;
}
//      判断链表是否已满
bool ListIsFull(const List * plist)
{
    List_Node * pt;
    bool is_full;
//    如果已经无法在申请动态分配的内存 那么判断为链表已满
//    我的想法并不是这个样子的 我原本想的是定义一个宏来控制链表的最大数量
    pt = (List_Node *) malloc(sizeof(List_Node));
    if (pt == NULL)
        is_full = true;
    else
        is_full = false;

    return is_full;
}
//      统计节点的数量
unsigned int ListItemCount(const List * plist)
{
    unsigned int count = 0;
//    设置为链表的开始
    List_Node * per_node = plist->head;
//    遍历每一个节点
    while (per_node != NULL)
    {
        count++;
        per_node= per_node->next;
    }

    return count;
}
//      在链表末尾添加节点
bool AddListItem(List * plist, const List_Item * item)
{
    List_Node * temp;
//    动态分配内存申请一个节点
    temp = (List_Node *) malloc(sizeof(List_Node ));
    if (temp == NULL)
        return false;
//    我不太明白为什么需要使用一个函数来进行结构体赋值
    temp->list_item = *item;
    temp->next = NULL;
//    如果last_node是第一个节点 则直接指向temp 如果不是则变为最后一个节点之后指向temp
    if (plist->end == NULL)
    {
        plist->head = temp;
        plist->end = temp;
    }
    else
        plist->end->next = temp;

    return true;
}
//      对链表每一个节点作用与p_function函数
void List_Traverse(const List * plist, void(* p_function)(List_Item item))
{
    List_Node * per_node = plist->head;

//    如果链表为空 打印错误信息
    if (ListIsEmpty(plist))
        fprintf(stderr, "The list is empty !!\n");
    else
        while (per_node != NULL)
        {
//        使用该函数作用与每一项节点
            p_function(per_node->list_item);
            per_node = per_node->next;
        }
}
//      设置链表为空 释放链表所占用的空间
void EmptyTheList(List * plist)
{
    List_Node * per_node;

//    如果链表为空 则打印错误信息
    if (ListIsEmpty(plist))
        fprintf(stderr, "The list is empty no need to empty again\n");
    else{
        while (plist->head != NULL)
        {
            per_node = plist->head->next; // 保存下一个节点的地址
            free(plist->head);              // 释放本节点内存
            plist->head = per_node;        // 另第一个节点为下一个节点地址
        }
    }
}