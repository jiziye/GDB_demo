#include<stdio.h>

int total = 0;

int square(int i)
{

    int result = 0;
    result = i * i;
    return result;
}

int main(int argc, char ** argv)
{
    int i;
    for (i = 0;i < 10; i++)
    {
        total += square(i);
    }
    return 0;
}


/*
多数时候需要在断点处执行一系列动作，gdb提供了在断点处执行命令的高级功能commands。
复制代码

比如需要对如上程序square参数i为5的时候断点，并在此时打印栈、局部变量以及total的值

编写gdb.init.
在gdb shell中source gdb.init，然后r执行命令，
(gdb) source gdb.init 
(gdb) r



显示栈帧

如果遇到断点而暂停执行，或者coredump可以显示栈帧。

通过bt可以显示栈帧，bt full可以显示局部变量
(gdb) bt 
(gdb) bt full

命令格式如下：

    bt

    bt full：不仅显示backtrace，还显示局部变量

    bt N：显示开头N个栈帧

    bt full N

单步执行

单步执行有两个命令next和step，两者的区别是next遇到函数不会进入函数内部，step会执行到函数内部。

如果需要逐条汇编指令执行，可以分别使用nexti和stepi。

继续执行

调试时，使用continue命令继续执行程序。程序遇到断电后再次暂停执行；如果没有断点，就会一直执行到结束。
    continue：继续执行

    continue 次数：继续执行一定次数。



*/