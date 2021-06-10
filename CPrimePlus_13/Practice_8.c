#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{
    char input_ch;
    char temp_ch;
    unsigned int count = 0;
    FILE * fp;

    if (argc < 2)
    {
        fprintf(stderr, "The program will count the character appeared in the files or your input\n");
        fprintf(stderr, "Usage: %s character filename1 filename2 filename3...\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (strlen(argv[1]) > 1)
        fprintf(stderr, "Please enter a character, not a string!.\n");

//    提取字符
    input_ch = argv[1][0];
//    说明读取标准输入
    if (2 == argc)
    {
        fprintf(stdout, "Please enter something. I will count the number of %c in your input.\n", input_ch);
        fprintf(stdout, "Command D to finish entered\n");
        while ((temp_ch = getchar()) != EOF)
            if (input_ch == temp_ch)
                count++;
        fprintf(stdout, "In your input character '%c' have appeared %u times.\n", input_ch, count);
    } else
    {
        for (int i = 0; i < argc - 2; ++i) {
            if ((fp = fopen(argv[i + 2], "r")) == NULL)
            {
                fprintf(stderr, "Error in opening the file %s.\n", argv[i + 2]);
                continue;
            }
            count = 0; // 初始化count
            while ((temp_ch = getc(fp)) != EOF)
                if (temp_ch == input_ch)
                    count++;
            fprintf(stdout, "In file %s, character '%c' have appeared %u times.\n", argv[i + 2], input_ch, count);
            if (fclose(fp) != 0)
                fprintf(stderr, "Error in closing the file %s.\n", argv[i + 2]);
        }
    }

    return 0;
}