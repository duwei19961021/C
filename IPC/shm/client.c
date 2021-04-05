#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include "comm.h"

int main()
{
	key_t key = ftok(PATHNAME, PROJ_ID);
	printf("key = %X\n",key);
	int shmid = shmget(key, SIZE, 0);
	if(shmid < 0)
	{
		perror("shmget failed.\n");
		return 1;
	}
	printf("shmid = %d\n",shmid);
	
	char* str = shmat(shmid, NULL, 0); // 关联共享内存

	char c = 'a'; // 操作系统不提供同步与互斥
	for(; c <= 'z'; c++)
	{
		str[c - 'a'] = c;
		sleep(5);
	}
	sleep(5);

	shmdt(str);

	sleep(5);
	return 0;
}
