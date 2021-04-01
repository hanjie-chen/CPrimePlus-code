#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000
#define STARS "************************************"

int main(void)
{
    printf("1    2    3    4    5    6    7    8    9    10\n");
    for (int i = 0; i < 10; ++i) {
//        在块里面定义 每次循环进行初始化
        unsigned short int count_1 = 0, count_2 = 0, count_3 = 0, count_4 = 0, count_5 = 0, count_6 = 0, count_7 = 0,
                count_8 = 0,count_9 = 0, count_10 = 0;
        srand(i);
        for (int j = 0; j < SIZE; ++j)
            switch ((rand() % 10) + 1) {
                case 1:
                    count_1++;
                    break;
                case 2:
                    count_2++;
                    break;
                case 3:
                    count_3++;
                    break;
                case 4:
                    count_4++;
                    break;
                case 5:
                    count_5++;
                    break;
                case 6:
                    count_6++;
                    break;
                case 7:
                    count_7++;
                    break;
                case 8:
                    count_8++;
                    break;
                case 9:
                    count_9++;
                    break;
                case 10:
                    count_10++;
                    break;
                default:
                    break;
            }
//        让其向左边对齐
        printf("%-5u%-5u%-5u%-5u%-5u%-5u%-5u%-5u%-5u%-5u\n", count_1, count_2, count_3, count_4, count_5, count_6, count_7,
               count_8, count_9, count_10);
    }

    puts("Done");


    return 0;
}