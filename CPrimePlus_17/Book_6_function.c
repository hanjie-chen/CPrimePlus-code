#include "Book_6.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 局部数据类型
typedef struct pair {
  Tree_Node * father_node;
  Tree_Node * children_node;
} Pair;
// 下面这些函数是接口函数的配套函数
static void CopyToNode(const Item * temp, Tree_Node * node_temp);
static Tree_Node * MakeNode(const Item * temp);
static void AddNode(Tree_Node * node_temp, Tree_Node * root);
static bool ToLeft(const Item * item_first,const Item * item_second);
static bool ToRight(const Item * item_first,const Item * item_second);
static Pair SeekItem(const Item * item,const Tree * point_tree);
static void DeleteNode(Tree_Node * * ptr);
static void InOrder(const Tree_Node * root, void (*function)(Item item));
static void DeleteAllNode(Tree_Node * root);

void InitializeTree(Tree * point_tree)
{
    point_tree->root = NULL;
    point_tree->size = 0;
}
bool TreeIsEmpty(const Tree * point_tree)
{
    return (point_tree->size == 0) ? true : false;
}
bool TreeIsFull(const Tree * point_tree)
{
    return (point_tree->size == MAX_TREE) ? true : false;
}
int TreeItemCount(const Tree * point_tree)
{
    return point_tree->size;
}
bool AddTreeNode(const Item * temp, Tree * point_tree)
{
    if (TreeIsFull(point_tree))
    {
        fputs("The tree is full can not add node, consider to delete one node!", stderr);
        return false;
    }
    Tree_Node * node_temp;
    if (SeekItem(temp, point_tree).children_node != NULL)
    {
        fputs("can not add the same item!", stderr);
        return false;
    }
    node_temp = MakeNode(temp);
    if (node_temp == NULL)
    {
        fputs("Can not creat node", stderr);
        return false;
    }
    point_tree->size++;
    if (point_tree->root == NULL)
        point_tree->root = node_temp;
    else
        AddNode(node_temp, point_tree->root);

    return true;
}
bool InTree(const Item * temp,const Tree * point_tree)
{
    return (SeekItem(temp, point_tree).children_node != NULL) ? true : false;
}
bool DeleteTreeNode(const Item * temp, Tree * point_tree)
{
    Pair look;

    look = SeekItem(temp, point_tree);
    if (look.children_node == NULL)
    {
        fputs("Can not find the pet! Please check!", stderr);
        return false;
    }
    if (look.father_node == NULL)  //查找的项为根节点
        DeleteNode(&point_tree->root);
    else if (look.father_node->left == look.children_node)
        DeleteNode(&look.father_node->left);
    else
        DeleteNode(&look.father_node->right);
    point_tree->size--;

    return true;
}
void Traverse(const Tree * point_tree, void (*function)(Item item))
{
    if (point_tree->root == NULL)
        fputs("The tree is empty!", stderr);
    else
        InOrder(point_tree->root, function);
}
void DeleteAll(Tree * point_tree)
{
    if (TreeIsEmpty(point_tree))
        fputs("The tree is empty, no need to empty again", stderr);
    else
        DeleteAllNode(point_tree->root);
    point_tree->root = NULL;
    point_tree->size = 0;
}

static void DeleteAllNode(Tree_Node * root)
{
    Tree_Node * pre_right;

    if (root != NULL)
    {
        pre_right = root->right;
        DeleteAllNode(root->left);
        free(root);
        DeleteAllNode(pre_right);
    }
}
static void InOrder(const Tree_Node * root, void (*function)(Item item))
{
    if (root != NULL)
    {
        InOrder(root->right, function);
        function(root->item);
        InOrder(root->left, function);
    }
}
static void DeleteNode(Tree_Node * * ptr)
{
//    注意ptr指向的是父节点中指针成员的地址
    Tree_Node * temp;

//    叶子节点为第一种情况的特殊情况
    if ((*ptr)->left == NULL)
    {
        temp = (*ptr);
        *ptr = (*ptr)->right;
        free(temp);
    }
    else if ((*ptr)->right == NULL)
    {
        temp = (*ptr);
        *ptr = (*ptr)->right;
        free(temp);
    }
    else // 如果被删除的节点存在两个子节点
    {
//        遍历到一个右子树为空的节点
        for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right)
            continue;
        temp->right = (*ptr)->right;
        temp = (*ptr);
        free(temp);
    }
}
static Pair SeekItem(const Item * item,const Tree * point_tree)
{
    Pair look;
//    初始化该结构体 一开始父节点没有指向 子节点指向根节点
    look.father_node = NULL;
    look.children_node = point_tree->root;
//    如果该树为空则提前返回无需检查
    if (look.children_node == NULL)
        return look;
//    如果节点到达了树的最末端则退出 说明没有找到相同的节点
    while (look.children_node != NULL)
    {
//        如果当前节点和目标节点不相同则向下遍历 如果相同则直接退出循环
        if (ToLeft(item, &(look.children_node->item)))
        {
            look.father_node = look.children_node;
            look.children_node = look.children_node->left;
        }
        else if (ToRight(item, &(look.children_node->item)))
        {
            look.father_node = look.children_node;
            look.children_node = look.children_node->right;
        }
        else
            break;
    }

    return look;
}
static Tree_Node * MakeNode(const Item * temp)
{
    Tree_Node * node_temp;

    node_temp = (Tree_Node *) malloc(sizeof(Tree_Node));
    if (node_temp != NULL)
    {
        CopyToNode(temp, node_temp);
        node_temp->left = node_temp->right = NULL;
    }

    return node_temp;
}
static void AddNode(Tree_Node * node_temp, Tree_Node * root)
{
//    使用递归让节点坐下走 因为根据比较结果发现该item需要放置在左边
    if (ToLeft(&node_temp->item, &root->item))
    {
        if (root->left == NULL)
            root->left = node_temp;
        else
            AddNode(node_temp, root->left);

    }
//        使用递归让节点往右下走
    else if (ToRight(&node_temp->item, &root->item))
    {
        if (root->right == NULL)
            root->right = node_temp;
        else
            AddNode(node_temp, root->right);
    } else{
        fputs("location error in AddNode() function!", stderr);
        exit(1);
    }
}
static bool ToLeft(const Item * item_first,const Item * item_second)
{
    int record;

    record = strcmp(item_first->pet_name, item_second->pet_name);
    if (record < 0)
        return true;
    else if (record == 0 && strcmp(item_first->pet_kind, item_first->pet_kind) < 0)
        return true;
    else
        return false;
}
static bool ToRight(const Item * item_first,const Item * item_second)
{
    int record;

    record = strcmp(item_first->pet_name, item_second->pet_name);
    if (record > 0)
        return true;
    else if (record == 0 && strcmp(item_first->pet_kind, item_first->pet_kind) > 0)
        return true;
    else
        return false;
}
static void CopyToNode(const Item * temp, Tree_Node * node_temp)
{
    node_temp->item = * temp;
}