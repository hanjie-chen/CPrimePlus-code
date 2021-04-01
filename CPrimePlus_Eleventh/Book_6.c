#include <stdio.h>

int main(void)
{
    const char * msg = "Don't be fool!";
    const char * copy;
//    copy只是指向了msg的值 并没有拷贝整个数组
    copy = msg;
    printf("%s\n", msg);
    printf("msg = %s, &msg = %p; value = %p\n", msg, &msg, msg);
    printf("copy = %s, &copy = %p; value = %p\n", copy, &copy, copy);

    return 0;
}