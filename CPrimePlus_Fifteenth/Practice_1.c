#include <stdio.h>

int binary_to_int(const char *);

int main(void)
{
    char * string1 = "11001001";
    char * string2 = "11001001";

    printf("The number of %s is %d\n", string1, binary_to_int(string1));
    printf("The number of %s is %d\n", string2, binary_to_int(string2));

    return 0;
}
/* 这个函数的局限性还是比较大的
 * 首先是这个代码的问题 使用while循环的部分有部分是重复的 可以再次函数化
 * 其次是这个实现的问题 只能对8位的字符串进行转换
 * 最后我写的代码中的位移运算运用的也没有很好
 * tips : 感觉可以先把字符串的位数给计算出来然后在处理 不然while循环之后会多移动一位 有点浪费了
 * 但是这个第一题要求不太高 我就不修改了
 * */
int binary_to_int(const char * string)
{
    int result = 0;

//    判断符号位
    if (*string == '0') // 如果大于0
    {
//        让字符串从符号位一到下一位
        string++;
        while (*string)
        {
            result |= (*string - '0'); // 让result一直赋值
            result <<= 1; // 让result左移一位
            string++; // 移动字符串
        }
//        多移动了一位
        result >>= 1;
    }
    else if (*string == '1') // 如果小于0
    {
        while (*string)
        {
            result |= (*string - '0'); // 让result一直赋值
            result <<= 1; // 让result左移一位
            string++; // 移动字符串
        }
//        多移动了一位
        result >>= 1;
        result = -((1 << 8) - result);
    }

    return result;
}