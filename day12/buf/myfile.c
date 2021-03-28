#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	close(1);
	int fd = open("log.txt", O_CREAT | O_APPEND  | O_WRONLY, 0644);
	if(fd < 0)
	{
		perror("open file failed.\n");
		exit(1);
	}
	const char *str1 = "hello world: write\n";
	const char *str2 = "hello world: printf\n";
	const char *str3 = "hello world: fprintf\n";
	size_t ret = write(fd,str1,strlen(str1));
	/*
	 * wirte不受缓冲方式影响
	 */

	printf(str2);
	fprintf(stdout,str3);
	/*
	 * 受缓冲方式影响，发生重定向之后缓冲发生改变，
	 * 变成了全缓冲，暂存在了当前进程的缓冲区(用户缓冲区,C语言提供的)，
	 * 在父进程中会fflush一次，子进程中又被fflush了一次，
	 * 因此log.txt中被写入了两次
	 */

	fork();

	fflush(stdout); // 将用户缓冲区的数据往操作系统里刷新
	close(fd);
	return 0;
}

/*
cat log.txt
hello world: write
hello world: printf
hello world: fprintf
hello world: printf
hello world: fprintf
*/
