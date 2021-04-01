#include <stdio.h>

#define SIZE 10

// 该函数只读取限定大小的输入 丢弃多余部分 并且把其中的换行符消除
char * s_gets(char * st, int n);

int main(void)
{
    char words[SIZE];
//    该函数会限定输入字符串的个数 个数=传入的数-1
    s_gets(words, SIZE);
    puts(words);

    return 0;
}
char * s_gets(char * st, int n)
{
    char * ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
//    这里的if表示ret_val的返回值不是NULL 回忆一下fgets函数读到文件结束或者文件读取失败会返回NULL
    if (ret_val)
    {
//        当输入是一个字符的时候
        while ('\n' != st[i] && '\0' != st[i])
            ++i;
//        如果没有填满的话就一定会有空格 那就把空格变为'\0'使之成为一个字符串
        if ('\n' == st[i])
            st[i] = '\0';
//        这里注意会把最后一个字符变为'\0'这样的话被填满的数组表示的就是一个字符串了
//        下面的操作把后面的输入全部消除了
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}