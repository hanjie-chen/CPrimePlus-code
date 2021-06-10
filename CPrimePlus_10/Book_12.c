#include <stdio.h>
#define SIZE 5
int main(void)
{
    int zippo[4][2] = {{2, 4}, {6, 8}, {1, 3}, {5, 7}};
//   下面这两个指针指向的是元素，即含有两个int类型的数组 采用的是元素首地址
//    int * p1 = zippo;
//    int * p2 = &zippo[0];
//    下面这两个指针指向的是数组 采用数组首地址
//    int * p3 = zippo[0];
//    int * p4 = &zippo[0][0];
//    zippo是一个二维数组，其中包含4个元素，每个元素有又是包含2个int类型的数组 一共4*2*个元素 占用了8*4个存储空间
//    其中zippo[0]是其第一个元素 该元素是一个包含了2个int类型的数组 故占用了2*4个元素的空间
//    printf("The size of zippo is %zd, the size of zippo[0] is %zd, the size of zippo[0][0] is %zd\n",
//            sizeof(zippo), sizeof(zippo[0]), sizeof(zippo[0][0]));
//    printf("The address of p1 is %p\nThe address of p2 is %p\nThe address of p3 is %p\nThe address of p4 is %p", p1, p2, p3, p4);

    printf("zippo is %p, zippo + 1 is %p\n", zippo, zippo +1);
    printf("zippo[0] is %p, zippo[0] + 1 is %p\n", zippo[0], zippo[0] + 1);
    printf("*zippo is %p, *zippo + 1 is %p\n", *zippo, *zippo + 1);
    printf("zippo[0][0] is %d\n", zippo[0][0]);
    printf("*zippo[0] is %d\n", *zippo[0]);
    printf("**zippo is %d\n", **zippo);
    printf("zippo[2][1] is %d\n", zippo[2][1]);
    printf("*(*(zippo + 2) + 1) = %d\n", *(*(zippo + 2) + 1));

    return 0;
}