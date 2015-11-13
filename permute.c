#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0


int main(){
	int programs[] = {-1,-1,-1}
	int number
	
	while(true){
		number = rand()%3;
		if(!isInside(number, programs) ){
			addToList(number, programs);
		}
	}
	return 0;
}

bool isInside(int j, int arr[]){
	int i;
	for(i = 0; i< 3; i++){
		if(arr[i]==j)return true;
	}
	return false;
}

void addToList(){
	
}
