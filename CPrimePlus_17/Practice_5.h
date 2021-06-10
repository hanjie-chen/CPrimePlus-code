#ifndef CPRIMEPLUS_SEVENTEENTH_PRACTICE_5_H
#define CPRIMEPLUS_SEVENTEENTH_PRACTICE_5_H
#include <stdbool.h>
/* 程序属性定义 */
#define STACK_MAX 20
// 节点的存储内容
typedef struct {
    char ch;
} Item;
// 节点的构成 内容+指向下一个节点的指针
typedef struct node {
    Item item;
    struct node * next;
}Node;
// 数据结构 栈
typedef struct {
    int item_count;
    Node * top;
} Stack;

/* 函数原型声明 */

// 操作       初始化一个栈
// 前置条件    point_stack指向一个栈
// 后置条件    栈被初始化
void InitializeStack(Stack * point_stack);

// 操作       判断栈是否为空
// 前置条件    point_stack指向一个初始化之后的栈
// 后置条件    如果栈为空则返回true 否则返回false
bool StackIsEmpty(const Stack * point_stack);

// 操作       判断栈是否为满
// 前置条件    point_stack指向一个初始化之后的栈
// 后置条件    如果栈为满则返回true 否则返回false
bool StackIsFull(const Stack * point_stack);

// 操作       确定栈中的项数
// 前置条件    point_stack指向一个初始化之后的栈
// 后置条件    返回栈中的项数
int StackItemCount(const Stack * point_stack);

// 操作       添加一个项到栈中
// 前置条件    point_stack指向一个初始化的栈
// 后置条件    栈中添加了一个节点 成功返回true 否则返回false
bool PushStackNode(Stack * point_stack, Item * point_item);

// 操作       把栈顶元素推出栈
// 前置操作    point_stack指向一个初始化的栈
// 后置操作    栈顶元素被推出 成功返回true 否则返回false
bool PopStackNode(Stack * point_stack, Item * item);

// 操作       将函数应用于每一项
// 前置操作    point_stack指向一个初始化的栈
// 后置操作    function指向的函数将作用于栈中的每一项
void Traverse(Stack * point_stack, void (* function)(Item item));

// 操作       判断该项是否在栈中
// 前置操作    point_stack指向一个初始化的栈
// 后置条件    如果该元素在栈中则返回true否则返回false
bool InStack(Stack * point_stack, Item * item);

// 操作       清空所有栈中元素
// 前置条件    point_stack指向一个初始化的栈
// 后置条件    栈中所有的元素被清空
void DeleteAllNode(Stack * point_stack);

#endif //CPRIMEPLUS_SEVENTEENTH_PRACTICE_5_H
