#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int status = 0;
	pid_t id = fork();
	if(id < 0)
	{
		perror("fork error!\n");		
	}
	else if(id == 0) // child
	{
		printf("i am child process\n");
		int count = 0;
		while (count < 3)
		{
			sleep(1);
			count++;
			printf("sleep 1\n");
		}
		int ret = 1/0;
		exit(10);
	}
	
	// parent
	printf("father wait before.\n");
	pid_t ret = waitpid(id,&status,0);
	printf("status = %d\n",status); // 保存子进程的返回状态
	
	if(WIFEXITED(status)) // 为真说明是正常退出的
	{
		printf("child exit code: %d\n",WEXITSTATUS(status));
	}
	else
	{
		printf("child exit error!\n");	
	}
//
//	if(ret > 0)
//	{
//		printf("子进程终止信号: %d\n", status & 0x7f); // 0 表示是正常退出
//		printf("子进程退出码: %d\n",(status >> 8) & 0xff);
//		printf("wait success!\n");
//		if(status & 0x7f) // 非0则说明子进程不是正常退出的
//		{
//			printf("child run error!\n");
//		}
//		else
//		{
//			if((status>>8) & 0xff) // 运行成功但是结果不正确
//			{
//				printf("child run success, but result is not right, exit code: %d\n",(status>>8)&0xff);
//			}
//			else
//			{
//				printf("child run success and result is right,exit code: %d\n",(status>>8)&0xff);
//			}
//		}
//	}
//	else
//	{
//		printf("wait failed!\n");
//	}

	printf("father wait after.\n");

	return 0;
}
