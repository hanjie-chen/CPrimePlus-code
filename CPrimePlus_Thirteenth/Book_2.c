#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 40

int main(int argc, char * argv[])
{
    FILE * in, * out;
    int ch;
    char name[LEN];
    int count = 0;

//    如果输入的参数不对
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
//    如果打开文件失败 那么返回错误信息并结束
    if ((in = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "I could't open the file \"%s\"\n", argv[1]);
        exit(EXIT_FAILURE);
    }
//    处理文件名
    strncpy(name, argv[1], LEN - 5);
    name[LEN - 5] = '\0';
    strcat(name, ".red");
//    如果创建文件失败
    if ((out = fopen(name, "w")) == NULL)
    {
        fprintf(stderr, "Can't create output file.\n");
        exit(EXIT_FAILURE);
    }
//    每间隔三个字符输入
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing file.\n");

    return 0;
}