#include <stdio.h>
#include <stdlib.h>

extern int sum(int value);

struct inout
{
    int value;
    int result;
};

int main(int argc,char *argv[])
{
    struct inout * io = (struct inout *)malloc(sizeof(struct inout));
    if (NULL == io)
    {
        printf("malloc failed. \n");
        return -1;
    }

    if(argc != 2)
    {
        printf("wrong para. \n");
        return -1;
    }

    io ->value = *argv[1] - '0';
    io ->result = sum(io->value);
    printf("your enter: %d, result: %d \n",io->value,io->result);
    return 0;
}

//make:gcc main.c sum.c -o main -g

/*
1. 设置断点可以通过b或者break设置断点，断点的设置可以通过函数名、行号、文件名+函数名、文件名+行号以及偏移量、地址等进行设置。

格式为：

    break 函数名

    break 行号

    break 文件名:函数名

    break 文件名:行号

    break +偏移量

    break -偏移量

    break *地址

   eg.(gdb) b sum.c sum

   查看断点，通过info break查看断点列表。
   eg. (gdb) info break  

   删除断点通过命令包括：

    delete <断点id>：删除指定断点

    delete：删除所有断点

    clear

    clear 函数名

    clear 行号

    clear 文件名：行号

    clear 文件名：函数名

断点还可以条件断住

    break 断点 if 条件；比如break sum if value==9，当输入的value为9的时候才会断住。

    condition 断点编号：给指定断点删除触发条件

    condition 断点编号 条件：给指定断点添加触发条件
    eg.(gdb) b sum if value == 9

断点还可以通过disable/enable临时停用启用。

    disable

    disable 断点编号

    disable display 显示编号

    disable mem 内存区域

     

    enable

    enable 断点编号

    enable once 断点编号：该断点只启用一次，程序运行到该断点并暂停后，该断点即被禁用。

    enable delete 断点编号

    enable display 显示编号

    enable mem 内存区域

 */