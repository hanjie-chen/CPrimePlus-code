static unsigned long int next = 1;

unsigned int rand_version0(void)
{
//     生成随机的数的公式
    next = next * 1103515245 + 12345;
    return (unsigned int) (next / 65536) % 32768;
}

void seed_rand(unsigned int seed)
{
    next = seed;
}