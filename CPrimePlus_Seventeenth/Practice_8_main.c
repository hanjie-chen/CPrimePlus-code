#include "Practice_8_tree.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char Menu(void);
void AddPet(Tree * point_tree);
void DropPet(Tree * point_tree);
void ShowPets(const Tree * point_tree);
void FindPets(const Tree * point_tree);
void Print_Tree_Item(Tree_Item * item);
void Print_List_Item(List_Item * item);
void UpperCase(char * string);
char * s_gets(char * string, int n);

int main(void)
{
    Tree pets;
    char choice;

    InitializeTree(&pets);
    while ((choice = Menu()) != 'q')
    {
        switch (choice) {
            case 'a':
                AddPet(&pets);break;
            case 'l':
                ShowPets(&pets);break;
            case 'f':
                FindPets(&pets);break;
            case 'n':
                printf("%d pets in clubs.\n", TreeItemCount(&pets));break;
            case 'd':
                DropPet(&pets);break;
            default:
                puts("Switching error!");
        }
    }
    DeleteAll(&pets);
    puts("Bye~");

    return 0;
}
char Menu(void)
{
    char ch;

    puts("Pet Club Membership Program");
    puts("Enter the letter corresponding your choice:");
    puts("a) add a pe       l) show list of pets");
    puts("n) number of pets f) find pets");
    puts("d) delete a pe    q) quit");
    while ((ch = getchar()) != EOF)
    {
        while (getchar() != '\n')
            continue;
        ch = tolower(ch);
        if (strchr("alnfdq", ch) == NULL)
            puts("Please enter a, l, n, f, d or q:");
        else
            break;
    }
    if (ch == EOF)
        ch = 'q';

    return ch;
}
void AddPet(Tree * point_tree)
{
    char pet_name[NAME_SIZE];
    List_Item listItem;
//    如果树已满则报错 如果未满则插入节点 把宠物信息的字符串全部变为大写字符
    if (TreeIsFull(point_tree))
        puts("No room in pet club! ");
    else
    {
        puts("Please enter the name of the pet:");
        s_gets(pet_name, NAME_SIZE);
        puts("Please enter the pet kind:");
        s_gets(listItem.pet_kind, KIND_NAME);
        UpperCase(pet_name);
        UpperCase(listItem.pet_kind);
        printf("The pet %s of %s will be write in club\n", pet_name, listItem.pet_kind);
        AddTreeNode(pet_name, &listItem, point_tree);
    }
}
void DropPet(Tree * point_tree)
{
    List_Item item;
    char pet_name[NAME_SIZE];

    if (TreeIsEmpty(point_tree))
        puts("No pets in pet club! ");
    else
    {
        puts("Please enter the name of the pet you want to delete:");
        s_gets(pet_name, NAME_SIZE);
        puts("Please enter the pet kind:");
        s_gets(item.pet_kind, NAME_SIZE);
        UpperCase(pet_name);
        UpperCase(item.pet_kind);
        printf("The pet %s of %s kind.", pet_name, item.pet_kind);
        if (DeleteTreeNode(pet_name, &item, point_tree))
            printf("is dropped from the club.\n");
        else
            printf("is not a member.\n");
    }
}
void ShowPets(const Tree * point_tree)
{
    if (TreeIsEmpty(point_tree))
        puts("The club is empty!");
    else
        Tree_Traverse(point_tree, Print_Tree_Item);
}
void Print_Tree_Item(Tree_Item * item)
{
    printf("The pet name is %s\n", item->pet_name);
    List_Traverse(&(item->pet_kind), Print_List_Item);
    printf("*******************************\n");
}
void Print_List_Item(List_Item * item)
{
    printf("The pet kind is %s\n", item->pet_kind);
}
void FindPets(const Tree * point_tree)
{
    Tree_Item item;

    if (TreeIsEmpty(point_tree))
        puts("No pets in pet club! ");
    else
    {
        puts("Please enter the name of the pet:");
        s_gets(item.pet_name, NAME_SIZE);
        UpperCase(item.pet_name);
        printf("The pet %s : \n", item.pet_name);
        if (InTree(&item, point_tree))
            List_Traverse(&(item.pet_kind), Print_List_Item);
        else
            printf("is not a member.\n");
    }
}
void UpperCase(char * string)
{
    while (*string)
    {
        *string = toupper(*string);
        string++;
    }
}
char * s_gets(char * string, int n)
{
    char * result;
    char * find;

    result = fgets(string, n, stdin);
    if (result)
    {
        find = strchr(string, '\n');
        if (find)
            * find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return result;
}