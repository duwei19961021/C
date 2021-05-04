#include <signal.h>
#include <stdio.h>

// int quit = 0;
volatile int quit = 0;
// 被volatile修饰的变量是不可被覆盖的，在任何执行流中读取该数据必须从该数据的真实存储位置读取，不能从任何缓存中读取。

void handler(int sig)
{
	quit = 1;	
}

int main()
{
	signal(2, handler);

	while(!quit); // 如果声明为int类型，quit会被优化为寄存器变量，while循环一直检测的是寄存器中的值，所以进程收到2号信号之后，修改的是内存上的值，寄存器上的值未被修改，所以进程没有退出

	printf("process exit\n");

	return 0;
}

