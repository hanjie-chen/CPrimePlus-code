#include <stdio.h>

// 该函数定义在别的文件中 需要使用extern来引入
extern unsigned int rand_version0(void);
extern void seed_rand(unsigned int seed);

int main(void)
{
    unsigned int seed;

    puts("Please enter your choice for the seed.");
    while (scanf("%u", &seed) == 1)
    {
//        初始化种子 让每次种子都不一样
        seed_rand(seed);
        for (int i = 0; i < 5; ++i)
            printf("%d\n", rand_version0());
        puts("Please enter your choice for the seed.(q to quit)");
    }puts("Done");

    return 0;
}