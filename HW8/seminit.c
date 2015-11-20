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
	union semun {
		int val;
		struct semid_ds *buf;
		ushort * array;
	} argument;
	argument.val = 0;
	id = semget(KEY, 1, 0666 | IPC_CREAT);
	if (id < 0) {
		fprintf(stderr, "Unable to obtain semaphore.\n");
		exit(0);
	}
	if (semctl(id, 0, SETVAL, argument) < 0) {
		fprintf(stderr, "Cannot set semaphore value.\n");
	}else {
	fprintf(stderr, "Semaphore %d initialized.\n", KEY);
	}
}
