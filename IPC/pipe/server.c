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
	umask(0000);
	int ret = mkfifo("FIFO", 0666);
	if (ret < 0)
	{
		perror("mkfifo error.\n");
		exit(-1);	
	}

	size_t fd = open("FIFO", O_RDONLY);
	if(fd >= 0)
	{
		char buf[64];
		while(1)
		{
			ssize_t len = read(fd, buf, sizeof(buf)-1);
			if(len > 0)
			{
				buf[len] = '\0';
				printf("client: %s", buf);
			}
			else if(len == 0)
			{
				printf("client quit,me too.\n")	;		
				exit(0);
			}
			else
			{
				perror("read error.\n");
				break;
			}
		}
	}
	return 0;
}
