#include "Practice_3.h"
#include <stdio.h>
#include <stdlib.h>

//      设置链表为空
void InitializeList(List * plist)
{
    plist->items_count = 0;
}
//      判断链表是否为空
bool ListIsEmpty(const List * plist)
{
    return (plist->items_count == 0) ? true : false;
}
//      判断链表是否已满
bool ListIsFull(const List * plist)
{
    return plist->items_count == MAX_SIZE;
}
//      统计节点的数量
unsigned int ListItemCount(const List * plist)
{
    return plist->items_count;
}
//      在链表末尾添加节点
bool AddItem(List * plist, Item item)
{
    if (ListIsFull(plist))
    {
        fputs("The list is full, can not add the item", stderr);
        return false;
    }
    else
    {
        plist->entries[plist->items_count] = item;
        plist->items_count++;
    }

    return true;
}
//      对链表每一个节点作用与p_function函数
void Traverse(const List * plist, void(* p_function)(Item item))
{
    for (int i = 0; i < plist->items_count; ++i)
        p_function(plist->entries[i]);
}
//      设置链表为空 释放链表所占用的空间
void EmptyTheList(List * plist)
{
    plist->items_count = 0;
}