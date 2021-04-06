#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEN 20
#define Seat_Count 12
#define Flight 4
#define FLIGHT_LEN_NAME 4

struct names {
    char first_name[LEN];
    char last_name[LEN];
};
//代表一个座位的状态
struct Giant_Airplane_Seat {
    int sequence_number;
    bool is_reserve;
    struct names people_name;
};

char * s_gets(char *, int); // 输入字符串
char Input_Choose(void); // 安全输入选择字符 并且做差错控制
void Show_Menu(void); // 打印菜单
void eat_line(void); // 处理多余字符
void Init_Airplane(struct Giant_Airplane_Seat (*ps)[Seat_Count], int flight); // 初始化结构数组
void Print_Empty_Seats(struct Giant_Airplane_Seat *, int); // 打印空余位置数量
void Print_Empty_Seats_List(struct Giant_Airplane_Seat *, int); // 打印空余座位列表
void Print_All_Seats(struct Giant_Airplane_Seat *, int); // 打印所有座位
void Choose_Function(char ch, struct Giant_Airplane_Seat * ps, int n); // 选择分支 选择功能
int Assign_Seats(struct Giant_Airplane_Seat *, int); // 预定座位
int Cancel_Reserve(struct Giant_Airplane_Seat *, int); // 取消座位预定

int main(void)
{
    struct Giant_Airplane_Seat fleet[Flight][Seat_Count];
    char * flight_sequence[Flight] = {"102", "311", "444", "512"};

//    初始化四个航班
    Init_Airplane(fleet, Flight);
    puts("This program is a ordering ticket system.You can reserve ticket.");
    while (1)
    {
        char flight[FLIGHT_LEN_NAME];
        int location;
        bool find_flight = false;
//        找到并确认顾客需要的航班
        puts("There are four flight: 102, 311, 444, 519. Please enter the flight number(000 to quit)");
        s_gets(flight, FLIGHT_LEN_NAME);
        if (strcmp(flight, "000") == 0)
            break;
        for (int i = 0; i < Flight; ++i)
            if (strcmp(flight, flight_sequence[i]) == 0)
            {
                location = i;
                find_flight = true;
                break;
            }
        if (!find_flight)
        {
            puts("Please under the guide of the tidy!");
            continue;
        }
        while (1)
        {
            char choose;
            printf("Now you are in %s flight.\n", flight_sequence[location]);
            Show_Menu();
            choose = Input_Choose();
            if ('f' == choose)
                break;
            Choose_Function(choose, fleet[location], Seat_Count);
        }
    }

    puts("Bye~");

    return 0;
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
void Show_Menu(void)
{
    puts("To choose a function, enter its letter label:");
    puts("a) Show number of empty seats");
    puts("b) Show list of empty seats");
    puts("c) Show alphabetical list of seats");
    puts("d) Assign a customer to a seat assignment");
    puts("e) Delete a seat assignment");
    puts("f) Quit");
}
char Input_Choose(void)
{
    char ch;

    ch = tolower(getchar());
    eat_line();
    while (strchr("abcdef", ch) == NULL)
    {
        puts("Please under the Guide of the menu");
        puts("Enter a, b, c, d, e or f");
        ch = tolower(getchar());
        eat_line();
    }

    return ch;
}
void Init_Airplane(struct Giant_Airplane_Seat (*ps)[Seat_Count], int flight)
{
    for (int i = 0; i < flight; ++i)
        for (int j = 0; j < Seat_Count; ++j) {
            ps[i][j].is_reserve = false;
            ps[i][j].sequence_number = j;
        }
}
void Print_Empty_Seats(struct Giant_Airplane_Seat * ps, int seat_count)
{
    int count = 0;

    for (int i = 0; i < seat_count; ++i)
        if (!ps[i].is_reserve)
            count++;
    printf("The total empty seats still have %d.\n", count);
}
void Print_Empty_Seats_List(struct Giant_Airplane_Seat * ps, int seats_count)
{
    for (int i = 0; i < seats_count; ++i)
        if (!ps[i].is_reserve)
            printf("The Seat-%d is empty.\n", i);
}
void Print_All_Seats(struct Giant_Airplane_Seat * ps, int seats_count)
{
    for (int i = 0; i < seats_count; ++i)
    {
        if (ps[i].is_reserve)
            printf("Seats-%d is be reserved ", i);
        else
            printf("Seats-%d is empty ", i);
        if ((i+1) % 6 == 0)
            printf("\n");
    }
}
void Choose_Function(char ch, struct Giant_Airplane_Seat * ps, int n)
{
    switch (ch) {
        case 'a':Print_Empty_Seats(ps, n);break;
        case 'b':Print_Empty_Seats_List(ps, n);break;
        case 'c':Print_All_Seats(ps, n);break;
        case 'd':Assign_Seats(ps, n);break;
        case 'e':Cancel_Reserve(ps, n);break;
        default:
            break;
    }
}
int Assign_Seats(struct Giant_Airplane_Seat * ps, int seats_count)
{
    int seat_sequence;
    char ch;

    puts("Please enter the seat sequence number you want to reserve");
    scanf("%d", &seat_sequence);
    eat_line();
    while (seat_sequence < 0 || seat_sequence > seats_count - 1)
    {
        puts("The seats sequence is between 0 ~ 11\nPlease enter again:");
        scanf("%d", &seat_sequence);
        eat_line();
    }
    while (ps[seat_sequence].is_reserve)
    {
        puts("Sorry, the seat already be reserved.\nPlease enter again:");
        scanf("%d", &seat_sequence);
        eat_line();
    }
    puts("Do you want to continue:Y/N");
    ch = tolower(getchar());
    eat_line();
    while (strchr("yn", ch) == NULL)
    {
        puts("Please enter y or n");
        ch = tolower(getchar());
        eat_line();
    }
    if ('n' == ch)
        return 0;
    ps[seat_sequence].is_reserve = true;
    puts("Now enter you name:");
    puts("Your first name:");
    s_gets(ps[seat_sequence].people_name.first_name, LEN);
    puts("Your last name:");
    s_gets(ps[seat_sequence].people_name.last_name, LEN);
    printf("Dear %s%s, you have successfully reserved Seat-%d.\n", ps[seat_sequence].people_name.first_name,
           ps[seat_sequence].people_name.last_name, seat_sequence);

    return 0;
}
int Cancel_Reserve(struct Giant_Airplane_Seat * ps, int seats_count)
{
    char full_name[2 * LEN];
    char temp[2 * LEN];
    int seat_sequence;
    char ch;

    puts("Please enter you Seat sequence, sir");
    scanf("%d", &seat_sequence);
    eat_line();
    while (seat_sequence < 0 || seat_sequence > seats_count - 1)
    {
        puts("The seats sequence is between 0 ~ 11\nPlease check and enter again:");
        scanf("%d", &seat_sequence);
        eat_line();
    }
    while (!ps[seat_sequence].is_reserve)
    {
        puts("Sorry, the seat do not be reserved.\nPlease check and enter again:");
        scanf("%d", &seat_sequence);
        eat_line();
    }
    puts("Do you want to continue:(Y/N)");
    ch = tolower(getchar());
    while (strchr("yn", ch) == NULL)
    {
        puts("Please enter y or n");
        ch = tolower(getchar());
        eat_line();
    }
    if ('n' == ch)
        return 0;
    strcpy(full_name, ps[seat_sequence].people_name.first_name);
    strcat(full_name, ps[seat_sequence].people_name.last_name);
    puts("Please enter your full name, sir");
    s_gets(temp, 2 * LEN);
    while (strcmp(temp, full_name) != 0)
    {
        printf("Your input name isn't match the name in system!\nPlease check and enter again.\n");
        s_gets(temp, 2 * LEN);
    }
    ps[seat_sequence].is_reserve = false;
    printf("Dear %s, Seats-%d reserve is successfully cancel.\n", full_name, seat_sequence);

    return 0;
}
