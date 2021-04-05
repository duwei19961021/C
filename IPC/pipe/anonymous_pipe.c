#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <wait.h>

int main()
{
	int fd[2];
	int ret = pipe(fd);
	if(ret != 0)
	{
		perror("open pipe failed.\n");
		exit(-1);
	}
	size_t pid = fork();
	if(pid == 0)
	{
		// child,write
		close(fd[0]);
		char buf[25] = "hello duwei1996\n";
//		int count = 0;
		while(1)
		{
			ssize_t len = write(fd[1], buf, strlen(buf));
			printf("child send %lu bytes.\n",len);
			printf("child say: hello duwei1996\n");
//			if(count++ == 5)
//			{
//				close(fd[1]);
//				break;
//			}
		}
		exit(0);
	}
	else
	{
		// parent,read
		char buf[25];
		close(fd[1]);
		int count = 0;
		while(1)
		{
			ssize_t len = read(fd[0], buf, sizeof(buf)-1);
			printf("parent get %lu bytes.\n",len);
			if(len > 0)
			{
				buf[len] = '\0';
			}
			printf("parent get: %s",buf);
			if(count++ == 10)
			{
				close(fd[0]);
				break;
			}
		}
		int status = 0;
		waitpid(pid, &status, 0);
		printf("child exit get a signal: %d\n", status & 0x7f); // child exit get a signal: 13
	}
	return 0;
}
