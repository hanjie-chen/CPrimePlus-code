//
// Created by 苹果 on 2020/10/31.
//
/* 这里需要说明的几点 这是我写的第一个头文件 有些注意事项就在这里说明了 不在后续的头文件里面说明
 * #ifndef xxx
 * #define xxx
 * #endif XXX
 * 使用这三个东西是为了防止声明冲突 当两个文件使用了同一个头文件的时候放在一起编译就会有大量的头文件声明冲突
 * 这样编译的时候就可以防止头文件被重复包含
 * */

#ifndef CPRIMEPLUS_NINTH_BOOK_8_H
#define CPRIMEPLUS_NINTH_BOOK_8_H

// add by chj
#define QUIT 5
#define HOTEL1 180.00
#define HOTEL2 225.00
#define HOTEL3 255.00
#define HOTEL4 355.00
#define DISCOUNT 0.95
#define STARS "**********************************"

int menu(void);
int get_nights(void);
void show_price(double rate, int nights);

#endif //CPRIMEPLUS_NINTH_BOOK_8_H

