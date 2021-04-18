#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void show_pending(sigset_t pending)
{
	for(int i = 1; i <= 31; i++)
	{
		if(sigismember(&pending, i)) // 1~31信号，挨个判断是否在pending信号集中并打印显示
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
	printf("\n");	
}

void handler(int signum)
{
	printf("get a signal: %d\n",signum);
}

int main()
{
	signal(2, handler);

	sigset_t pending;

	sigset_t block, oblock;

	sigisemptyset(&block); // 先对block进行初始化，设置全0，这里修改的只是参数block，而不是修改的当前进程的信号屏蔽字

	sigisemptyset(&pending); // 同上，初始化pending，设置全0

	sigaddset(&block, 2); // 将2号信号添加进block

	sigprocmask(SIG_SETMASK, &block, &oblock); // 修改当前进程的信号屏蔽字，等于block。也就是使当前进程屏蔽2号信号

	int count = 0;

	while(1)
	{
		sigemptyset(&pending);

		sigpending(&pending); // 获取当前进程的pending信号集

		show_pending(pending);

		sleep(1);

		if(count++ == 10)
		{
			printf("recover sig mask.\n");
			sigprocmask(SIG_SETMASK, &oblock, NULL);
		}
	}
	return 0;
}
