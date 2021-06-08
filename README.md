## 中文说明：

## C Prime Plus 课本代码和编程练习答案

> 作者：陈翰杰
>
> 环境：MacOS Big Sur && CLion 2020.1
>
> 注意：本仓库包含的课后习题和需要编写代码的复习题是由本人自己写的，并不是标准答案，仅供参考。

***

#### Part1: 在这里说明一下文件夹的命名

```c
CPrimePlus_章节号
```

#### 然后说明一下每个文件夹包含的文件 包含5种类型

```c
main.c				       --用于记录开启每章的时间和自己的一些想法
Book_序号.c			       --本章中书中的代码 注意和书中的顺序可能不同
Review_序号.c		               --本章复习题中需要写代码的习题
Practice_序号.c		      	       --本章课后练习题
CMakeLists.txt			       --CLion的编译文件 因为需要编译多个main函数
```

***

#### Part2: 关于代码的一些说明

- 这个练习题答案从C Prime Plus 的第三章开始，前两章练习题太简单，故没有放上去。

- 本代码中几乎所有和文件进行交互的程序（第14章）是通过gcc编译的，几乎所有的接受命令行参数的程序是通过gcc编译的

- 从第九章Book_8_main.c之前的代码都是使用下面的形式引入stdio.h

```c
#include "stdio.h"
```

这个错误在写Book_8的时候才注意到在后面的章节中已经进行了修正 使用了正确的形式引入stdio.h

```c
#include <stdio.h>
```

两者的区别在Book_8_main.c的注释中有说明

***

#### Part3: 关于Clion中读取文件的问题

因为CLion把编译好的可执行文件放到本地的cmake-build-debug目录下，所以如果需要读取文件的话，需要把该文件放到该目录下

如果使用gcc编译的话则没有关系，因为生成的可执行文件和需要读取的文件在同一个目录下。

***

***

## English Version：

## C Prime Plus Book Code and Programming Exercise Answers

> Author : Hanjie Chen
>
> Environment: macOS Big Sur && Clion 2021.1
>
> Attention: this repository contains the book source and programming exercise answers; And the answers are coded by author, not the standard answer, for reference only
>

***

#### Part1: How I named the folder

```c
CPrimePlus_ChapterSequence
```

#### The folder contain the 5 type file

```c
main.c				       --record the time per chapter start and my idea;(writed by Chinese)
Book_Sequence.c			       --book code; may be different with book
Review_Sequence.c		       --the review program
Practice_Sequence.c		       --exercise answer
CMakeLists.txt			       --cmakelist of CLion because it need to complie mutiple main function
```

***

#### Part2: Some profile about the code

- The practice answer start from third Chapter, because the firt Chapter and the Second Chapter is too simple.

- Nearly all code in Chapter 14 is complied by gcc and all porgram that accepted command line argument is complied by gcc

- The code before Chapter Ninth Book_8_main.c using the following format include head file

  ```c
  #include "stdio.h"
  ```

  I noticed the error and fixed it in follow-up chapter code using the more correct way to include head file such as

  ```c
  #include <stdio.h>
  ```

  the difference between <> and "" was explain in Book_8_main.c in Chinese


***

#### Part3: The CLion program communicate with file

CLion will puts the executable file into the directory of cmake-bulid-debug, so if you want to read or write file, you should put the file into the directory.If you don't do that you will depressed find that your program can not find the file.

If you compile the program with gcc, beacuse the executable file and the file you want to communicate are in the same directory, so you no need to do such things above.
