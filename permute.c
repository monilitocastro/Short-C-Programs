#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int isInside(int, int[]);
void addFlag(int, int[]);
void printFlags(int[]);

int main(){
	int items[] = {  -1, -1, -1};
	int a1,a2,a3;

		for(a1 = 0; a1 < 3; a1++){
			if(isInside(a1, items) == TRUE){ continue;}
			addFlag(a1, items);
				for(a2 = 0; a2 < 3; a2++){
					if(isInside(a2, items) == TRUE ){ continue;}
					addFlag(a2, items);
					for(a3 = 0; a3 < 3; a3++){
						if(isInside(a3, items) == TRUE ){ continue;}
						addFlag(a3, items);
						printFlags(items);
						items[3]=-1;
					}	
				items[2]=-1;
				}
		items[1]=-1;	
		}
	
	printf("\n");
	return 0;
}

int isInside(int j, int arr[]){
	int i;
	for(i =0; i< 3; i++){
		if( arr[i]==j )return TRUE;
	}
	return FALSE;
}

void addFlag(int j, int arr[]){
	int i;
	for(i =0; i< 3; i++){
		if( arr[i]==-1){
			arr[i] = j;
			return;
		}
	}
}
void printFlags(int arr[]){
	int i;
	for(i =0; i< 3; i++){
		printf("[%d,%d,%d,%d]\n",arr[0],arr[1],arr[2],arr[3]);
	}
}
