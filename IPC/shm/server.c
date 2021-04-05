#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include "comm.h"

int main()
{
	key_t key = ftok(PATHNAME, PROJ_ID); // 将PATHNAME和PROJ_ID作为信息源，生成一个唯一的key值(在系统中保证唯一)
	printf("key = %X\n",key);
	int shmid = shmget(key, SIZE, IPC_CREAT | IPC_EXCL | 0666); // 生命周期跟随操作系统，申请之后要释放 
	if(shmid < 0)
	{
		perror("shmget failed.\n");
		return 1;
	}
	printf("shmid = %d\n",shmid);
	
	char* str = shmat(shmid, NULL, 0); // 关联共享内存

	while(1)
	{
		sleep(1);
		printf("msg: %s\n", str);
	}

	sleep(10);

	shmdt(str);

	sleep(10);
	printf("I will rm ipc source right now, shmid = %d\n",shmid);
	shmctl(shmid, IPC_RMID, NULL);
	return 0;
}
