cmake_minimum_required(VERSION 3.19)
project(CPrimePlus_Seventeenth C)

set(CMAKE_C_STANDARD 99)

add_executable(CPrimePlus_Seventeenth main.c)
add_executable(CPrimePlus_Seventeenth_Book_1 Book_1.c)
add_executable(CPrimePlus_Seventeenth_Book_2 Book_2.c)
add_executable(CPrimePlus_Seventeenth_Book_3 Book_3.h Book_3_main.c Book_3_function.c)
add_executable(CPrimePlus_Seventeenth_Book_4 Book_4.h Book_4_main.c Book_4_function.c)