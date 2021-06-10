// 在同一个内存空间存储不同的数据类型 (一次存储一种类型)
// 编译器会分配联合中占用最大字节类型的数据的空间给联合
union hold {
    int digit;
    double number;
    char letter;
};

struct owner_person {
    char person_name[20];
    int age;
};
struct owner_organization {
    char organization_name[20];
    char headquarter[20];
};
union data {
    struct owner_person own_car;
    struct owner_organization lease_car;
};
struct car_data {
    char make[15];
    int status; // 0 属于人 1 属于租车组织
    union data owner_info; // 更具status来选择是哪一种结构
};


int main(void)
{
    union hold fit;
    union hold * pu;

    fit.digit = 23; // 存储整形数23
    fit.number = 34.34; // 清除整形数23 存储双精度浮点数34.34
    fit.letter = 'A'; // 清除浮点数34.34 存储字符A

    pu = &fit;
    int x = pu->digit; // 联合的指针用法和结构相同


}