#ifndef CPRIMEPLUS_SEVENTEENTH_PRACTICE_7_H
#define CPRIMEPLUS_SEVENTEENTH_PRACTICE_7_H
#include <stdbool.h>

/* 数据属性 */
#define WORD_SIZE 20
#define MAX_TREE 100
typedef struct {
    char word[WORD_SIZE];
    int word_count;
} Item;
typedef struct tree_node {
    Item item;
    struct tree_node * left;  // 指向左节点的指针
    struct tree_node * right; // 指向右节点的指针
} Tree_Node;
typedef struct {
    Tree_Node * root;
    int size;
} Tree;
/* 数据操作 */
/* 函数原型 */

// 操作       初始化一棵树
// 前置条件    point_tree指向一棵树
// 后置条件    树被初始化为空
void InitializeTree(Tree * point_tree);

// 操作       判断树是否为空
// 前置条件    point_tree指向一棵树
// 后置条件    如果为空则返回true 否则返回false
bool TreeIsEmpty(const Tree * point_tree);

// 操作       判断树是否已满
// 前置条件    point_tree指向一棵树
// 后置条件    如果已满则返回true 否则返回false
bool TreeIsFull(const Tree * point_tree);

// 操作       计算树的节点个数
// 前置条件    point_tree指向一棵树
// 后置条件    返回树的节点个数
int TreeItemCount(const Tree * point_tree);

// 操作       添加树的节点
// 前置条件    temp指向待添加项的地址 point_tree指向一棵已经初始化的树
// 后置条件    如果添加成功则返回true 否则返回false
bool AddTreeNode(const Item * temp, Tree * point_tree);

// 操作       在树中查找一个项
// 前置条件    point_tree指向一个已初始化的树 temp指向待查找的项
// 后置条件    如果找到则返回true并且把该节点中单词的个数赋值给temp 否则返回false
bool InTree(Item * temp, const Tree * point_tree);

// 操作       在数中删除一个项
// 前置条件    point_tree指向一颗初始化的树 temp指向待删除的指针
// 后置条件    如果删除成功则返回true 否则返回false
bool DeleteTreeNode(const Item * temp, Tree * point_tree);

// 操作       把函数function用于树节点的每一项
// 前置条件    point_tree指向一颗初始化的树 function指向一个无返回值 接收一个为Item类型的参数的函数指针
// 后置条件    函数function作用域树的每一项
void Traverse(const Tree * point_tree, void (*function)(Item item));

// 操作       删除树中的所有内容
// 前置条件    point_tree指向一颗已经初始化的树
// 后置条件    释放所有树所占用的内存空间
void DeleteAll(Tree * point_tree);

#endif //CPRIMEPLUS_SEVENTEENTH_PRACTICE_7_H
