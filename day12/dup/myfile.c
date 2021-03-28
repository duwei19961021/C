#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int fd = open("log.txt", O_CREAT | O_APPEND  | O_WRONLY, 0644);
	if(fd < 0)
	{
		perror("open file failed.\n");
		exit(1);
	}

	dup2(fd,stdout->_fileno); // 将fd重定向至标准输出
	close(fd);

	const char *str1 = "hello world: write\n";
	const char *str2 = "hello world: printf\n";
	const char *str3 = "hello world: fprintf\n";
	size_t ret = write(fd,str1,strlen(str1));

	printf(str2);
	fprintf(stdout,str3);

	fork();

	fflush(stdout);
	return 0;
}
