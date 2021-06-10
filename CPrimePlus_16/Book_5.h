// 如果检测到未定义该宏 即第一次包含该文件 那么就执下面的内容
// 如果检测到已经定义过该宏 那么就不会执行下面的这些内容
#ifndef CPRIMEPLUS_SIXTEENTH_BOOK_5_H
#define CPRIMEPLUS_SIXTEENTH_BOOK_5_H

#include <string.h>
#define S_LEN 32
// 结构申明 并且定义类型
typedef struct {
    char first_name[S_LEN];
    char last_name[S_LEN];
} names;

void get_names(names *);
void show_names(const names *);
char * s_gets(char * string, int n);

#endif //CPRIMEPLUS_SIXTEENTH_BOOK_5_H
