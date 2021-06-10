#include <stdio.h>

int main(void)
{
//    使用字符串初始化数组
    const char word1[40] = "chj666";
//    使用标准形式初始化数组 如果没有最后的空字符 该数组就是字符数组 而不是字符串
//    虽然是这么说的 但是字符数组中的未被初始化的元素会被初始化为\0 其实两者是没有区别的
    const char word2[40] = {'c', 'h', 'j', '6', '6', '6', '\0'};
//    使用双引号括起来的内容被视为指向该字符串存储位置的指针
    printf("%s %p %c\n", "We", "are", *"space passengers");
    puts(word1);
    puts(word2);

    return 0;
}