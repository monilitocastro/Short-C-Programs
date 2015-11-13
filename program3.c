#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define KEY (1492)
void main(){
	int id;
	struct sembuf operations[1];
	int retval;
	id = semget(KEY, 1, 0666);
	if (id < 0) {
		fprintf(stderr, "Cannot find semaphore, exiting.\n");
		exit(0);
	}
	/* Do a semaphore P - operation (an acquire operation). */
	operations[0].sem_num = 0;
	operations[0].sem_op =-1;
	operations[0].sem_flg = IPC_NOWAIT;
	retval = semop(id, operations, 1);
	if (retval == 0) {
		printf("Successful P-operation by program SemB.\n");
		printf("Process id is %d\n", getpid());
	} else {
		printf("SemB: P - operation did not succeed.\n");
	}
}
