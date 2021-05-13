#include "Book_3.h"
#include <stdio.h>
#include <stdlib.h>

static void CopyToNode(Item item, Node * p_node);

//      设置链表为空
void InitializeList(List * plist)
{
    *plist = NULL;
}
//      判断链表是否为空
bool ListIsEmpty(const List * plist)
{
    return (*plist == NULL) ? true : false;
}
//      判断链表是否已满
bool ListIsFull(const List * plist)
{
    Node * pt;
    bool is_full;
//    如果已经无法在申请动态分配的内存 那么判断为链表已满
//    我的想法并不是这个样子的 我原本想的是定义一个宏来控制链表的最大数量
    pt = (Node *) malloc(sizeof(Node));
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
    Node * per_node = * plist;
//    遍历每一个节点
    while (per_node != NULL)
    {
        count++;
        per_node= per_node->next;
    }

    return count;
}
//      在链表末尾添加节点
bool AddItem(List * plist, Item item)
{
    Node * last_node = *plist;
    Node * temp;
//    动态分配内存申请一个节点
    temp = (Node *) malloc(sizeof(Node));
    if (temp == NULL)
        return false;
//    我不太明白为什么需要使用一个函数来进行结构体赋值
//    temp->item = item;
    CopyToNode(item, temp);
    temp->next = NULL;
//    如果last_node是第一个节点 则直接指向temp 如果不是则变为最后一个节点之后指向temp
    if (last_node == NULL)
        *plist = temp;
    else{
        while (last_node->next != NULL)
            last_node = last_node->next;
        last_node->next = temp;
    }

    return true;
}
//      对链表每一个节点作用与p_function函数
void Traverse(const List * plist, void(* p_function)(Item item))
{
    Node * per_node = * plist;

//    如果链表为空 打印错误信息
    if (per_node == NULL)
        fprintf(stderr, "The list is empty !!\n");
    else
        while (per_node != NULL)
        {
//        使用该函数作用与每一项节点
            p_function(per_node->item);
            per_node = per_node->next;
        }

}
//      设置链表为空 释放链表所占用的空间
void EmptyTheList(List * plist)
{
    Node * per_node;

//    如果链表为空 则打印错误信息
    if (*plist == NULL)
        fprintf(stderr, "The list is empty no need to empty again\n");
    else{
        while (*plist != NULL)
        {
            per_node = (*plist)->next; // 保存下一个节点的地址
            free(*plist);              // 释放本节点内存
            * plist = per_node;        // 另第一个节点为下一个节点地址
        }
    }
}
//      拷贝函数 把一个item拷贝到其中一个节点上去
static void CopyToNode(Item item, Node * p_node)
{
    p_node->item = item;
}