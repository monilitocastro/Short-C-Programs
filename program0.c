// Seminit–Semaphore initialization.
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
/*
KEY is an arbitrary long integer which serves as an
external identifier for any program that wishes to use it.
*/
#define KEY (1492)
void main(){
	int id;
	struct sembuf operations[1];
	int retval;
	union semun {
		int val;
		struct semid_ds *buf;
		ushort * array;
	} argument;
	argument.val = 0;
	id = semget(KEY, 3, 0666 | IPC_CREAT);
	if (id < 0) {
		fprintf(stderr, "Program 0: Unable to obtain semaphore.\n");
		exit(0);
	}
	if (semctl(id, 0, SETVAL, argument) < 0) {
		fprintf(stderr, "Program 0: Cannot set semaphore value.\n");
	}else {
	fprintf(stderr, "Program 0: Semaphore %d initialized.\n", KEY);
		operations[0].sem_num = 0;
		operations[0].sem_op = 1;
		operations[0].sem_flg = 0;
		retval = semop(id, operations, 1);
		if (retval == 0) {
			printf("Program 0: Successful V-operation.\n");
		} else {
			printf("Program 0: SemA: V -operation did not succeed.\n");
			perror("Program 0: REASON");
		}
	}
}
