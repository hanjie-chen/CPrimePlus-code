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
