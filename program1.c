#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define KEY (1490)
int main(){
	int id;
	struct sembuf operations[2];
	int retval;
	id = semget(KEY, 1, 0666);
	if (id < 0) {
		fprintf(stderr, "Cannot find semaphore, exiting.\n");
		return(0);
	}
	/* Do a semaphore V - operation (a blocking operation). */
	operations[0].sem_num = 0;
	operations[0].sem_op = -1;
	operations[0].sem_flg = IPC_NOWAIT;
	/* Do a semaphore P - operation (a release operation). */
	operations[1].sem_num = 1;
	operations[1].sem_op = 1;
	operations[1].sem_flg = IPC_NOWAIT;
	retval = semop(id, operations, 1);
	if (retval == 0) {
		printf("Program1: Successful P-operation.\n");
	} else {
		perror("REASON");
	}

return(1);
}
