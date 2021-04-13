// 在位域的数据结构中不能根据数据类型计算长度
// 注意位域的宽度不能超过其依附的数据类型的长度

// 位字段 数值表明字段的宽度
struct {
    unsigned int autfd : 1;
    unsigned int bldfc : 1;
    unsigned int undln : 1;
    unsigned int itals : 1;
} prnt;
// 创建了2位的字段和8位的字段
struct {
    unsigned int code1 : 2;
    unsigned int code2 : 2;
    unsigned int code3 : 8;
} prcode;

int main(void)
{
//    由于每一位只有一个字段 故只能赋值为0/1
    prnt.autfd = 0;
    prnt.bldfc = 1;
//    注意赋值不能超过字段可容纳的范围
    prcode.code1 = 0;
    prcode.code2 = 3;
    prcode.code3 = 102;

    return 0;
}