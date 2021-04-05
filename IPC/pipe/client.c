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
	size_t fd = open("FIFO", O_WRONLY);
	if(fd >= 0)
	{
		char buf[64];
		while(1)
		{
			printf("Please Enter Message: ");
			fflush(stdout);
			ssize_t rlen =  read(0, buf, sizeof(buf)-1);
			if(rlen > 0)
			{
				buf[rlen] = 0;
				write(fd, buf, rlen);
			}
		}
	}
	return 0;
}
