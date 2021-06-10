#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define LEN 20
#define SIZE 4

struct name {
    char first_name[LEN];
    char last_name[LEN];
};
struct student {
    struct name names;
    float grade[3];
    float average;
};
const char * subject[3] = {
        "Math",
        "English",
        "Data Struct"
};

int Input_Information(struct student *, int );
char * s_gets(char * string, int n);
void eat_line(void);
void calculate_average(struct student *);
void Print_Information(struct student *, int );
void Print_Class_Average(struct student *, int );
void Input_Grade(struct student *, int );
void ToLower(char * );
bool Judge_Enter(struct student *, int );

int main(void)
{
//    部分初始化结构体
    struct student people[SIZE] = {
            {"Chen", "han", {}, -1},
            {"Zha", "yu", {}, -1},
            {"Ti", "jin", {}, -1},
            {"Li", "yong", {}, -1},
    };
    bool enter_finish = false;
    int input_count = 0;

//    学生列表
    printf("Here are %d students\n", SIZE);
    for (int i = 0; i < SIZE; ++i)
        printf("Student-%d:%s%s  ",i , people[i].names.first_name, people[i].names.last_name);
    printf("\n");
//     输入学生信息
    puts("The next is enter the information of students");
    while (!enter_finish)
    {
//        输入学生信息 输入成绩完毕之后计算成绩平均值
        if (Input_Information(people, SIZE))
        {
            puts("Can't find the student! Please try again");
            continue;
        }
        input_count++;
//        如果输入次数大于学生人数 那么输出未输入的学生的姓名
        if (input_count >= SIZE)
            for(int i = 0; i < SIZE; ++i)
                if (people[i].average < 0)
                    printf("Student-%d: %s%s have't enter grade.\n", i, people[i].names.first_name, people[i].names.last_name);
//        判断是否还存在学生没有输入成绩 如果有那么继续循环
        enter_finish = Judge_Enter(people, SIZE);
    }

//    打印所有人的成绩
    Print_Information(people, SIZE);
//    打印每门课的班级平均值
    Print_Class_Average(people, SIZE);

    return 0;
}
int Input_Information(struct student * ps, int n)
{
    char input_name[2 * LEN], student_name[2 * LEN]; // 输入名和学生名
    int location; // 用于定位是那个学生
    bool flag = false;
//    输入全名并且全部转换为小写字母
    puts("Please enter the student full name:");
    s_gets(input_name, 2 * LEN);
    ToLower(input_name);
//    寻找这个学生
    for (location = 0; location < n; ++location)
    {
//        生成学生名的全写并且转换为小写
        strncpy(student_name, ps[location].names.first_name, LEN);
        strncat(student_name, ps[location].names.last_name, LEN);
        ToLower(student_name);
        if (strcmp(input_name, student_name) == 0)
        {
            flag = true;
            break;
        }
    }
//    如果找不到这个学生 那么返回1
    if (!flag)
        return 1;
//    输入成绩
    Input_Grade(ps, location);
//    计算每个学生三门课程的平均分
    calculate_average(&ps[location]);

    return 0;
}
void calculate_average(struct student * ps)
{
        ps->average = (ps->grade[0] + ps->grade[1] + ps->grade[2]) / 3;
}
void Print_Information(struct student * ps, int n)
{
    for (int i = 0; i < n; ++i) {
        printf("Student: %s%s\n", ps[i].names.first_name, ps[i].names.last_name);
        printf("Math: %.2f English: %.2f Data Struct: %.2f\n", ps[i].grade[0], ps[i].grade[1], ps[i].grade[2]);
        printf("The average of grade is %.2f\n", ps[i].average);
    }
}
void Print_Class_Average(struct student * ps, int n)
{
    float average_math, average_english, average_data;
    float total_math = 0, total_english = 0, total_data = 0;

    for (int i = 0; i < n; ++i) {
        total_math += ps[i].grade[0];
        total_english += ps[i].grade[1];
        total_data += ps[i].grade[2];
    }
    average_math = total_math / n;
    average_english = total_english / n;
    average_data = total_data / n;

    printf("The average of the math in class is %.2f and the English is %.2f and the Data Struct is %.2f\n",
            average_math, average_english, average_data);
}
char * s_gets(char * string, int n)
{
    char * result;
    char * find;

    result = fgets(string, n, stdin);
    if (result)
    {
        find = strchr(string, '\n');
        if (find)
            * find = '\0';
        else
            eat_line();
    }

    return result;
}
void eat_line(void)
{
    while (getchar() != '\n')
        continue;
}
void Input_Grade(struct student * ps, int location)
{
//    记录输入状态
    int input_status;

    printf("Now enter the grade of %s%s\n", ps[location].names.first_name, ps[location].names.last_name);
    for (int i = 0; i < 3; ++i) {
        printf("Please enter the %s grade.\n", subject[i]);
//        处理错误输入 范围错误 和 输入数据类型错误
        while (true)
        {
            input_status = scanf("%f", &ps[location].grade[i]);
            eat_line();
            if (input_status)
                if (ps[location].grade[i] > 100 || ps[location].grade[i] < 0)
                {
                    puts("The Grade range is between 0 ~ 100 Please enter again!");
                    continue;
                } else
                    break;
            else
                printf("Please enter the number as the grade in range of 0 ~ 100.\n");
        }
    }
    printf("%s%s grade is entered success!.\n", ps[location].names.first_name, ps[location].names.last_name);
}
void ToLower(char * string)
{
    while (* string)
    {
        if (isupper(* string))
            * string = tolower(* string);
        string++;
    }
}
bool Judge_Enter(struct student * ps, int n)
{
    bool result = true;

    for (int i = 0; i < n; ++i)
        if (ps[i].average < 0)
            result = false;

    return result;
}