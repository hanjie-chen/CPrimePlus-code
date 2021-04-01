#include <stdio.h>
#include <stdlib.h>

#define CNT_Z '\032'
#define STR_LEN 81

int main(void)
{
    char filename[STR_LEN];
    char ch;
    FILE * fp;
    long count, last;

    puts("Enter the name of file to be processed: ");
    fscanf(stdin, "%80s", filename); // 最后一个值用于保存 '\0'
    if ((fp = fopen(filename, "rb")) == NULL)
    {
        printf("can't open %s by read only\n", filename);
        exit(EXIT_FAILURE);
    }
//    fseek() 第二个参数用于微调 第三个参数用于大致调整当前所在的位置 第二个参数的单位是字节数
//    把文件指针定位到文件结束的位置
    fseek(fp, 0L, SEEK_END);
//    计算当前文件位置 和 文件开始出的字节数 并且 赋值给last
    last = ftell(fp);
    for (count = 1L; count <= last; ++count)
    {
//        逆序拨动文件指针
        fseek(fp, -count, SEEK_END);
        ch = getc(fp);
        if (ch != CNT_Z && ch != '\r')
            putc(ch, stdout);
    }
    putchar('\n');
    if (fclose(fp) != 0)
    {
        printf("Can't close the file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    return 0;
}