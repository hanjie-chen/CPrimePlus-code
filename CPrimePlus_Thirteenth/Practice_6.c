#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 40

int main(void)
{
    FILE * in, * out;
    int ch;
    char output_filename[LEN];
    char input_filename[LEN];
    int count = 0;

    fputs("This program will reduce one file and create the file .red to save the reduce content\n", stdout);
    fputs("Please enter the filename of the file you want to reduce.\n", stdout);
    scanf("%s", input_filename);
//    如果打开文件失败 那么返回错误信息并结束
    if ((in = fopen(input_filename, "r")) == NULL)
    {
        fprintf(stderr, "I could't open the file \"%s\"\n", input_filename);
        exit(EXIT_FAILURE);
    }
//    处理文件名
    strncpy(output_filename, input_filename, LEN - 5);
    output_filename[LEN - 5] = '\0';
    strcat(output_filename, ".red");
//    如果创建文件失败
    if ((out = fopen(output_filename, "w")) == NULL)
    {
        fprintf(stderr, "Can't create output file.\n");
        exit(EXIT_FAILURE);
    }
//    每间隔三个字符输入
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);
    fputs("The reduce is finish and success!.\nPlease check out", stdout);
    fprintf(stdout, "The .red file have %d characters.\n", count);
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing file.\n");

    return 0;
}