#include <stdio.h>
#include <stdlib.h>

public void main(){
	int bits = 1;
	int a2,a3,a5,a7;
	for(a2 = 0; a2 < 4; a2++){
		if(bits % a2 == 0 ){ continue;}
		bits *= a2;
		printf("%d ",a2);
		for(a3 = 0; a3 < 4; a3++){
			if(bits % a3 == 0 ){ continue;}
			bits *= a3;
				for(a5 = 0; a5 < 4; a5++){
					if(bits % a5 == 0 ){ continue;}
					bits *= a5;
					for(a7 = 0; a7 < 4; a7++){
						if(bits % a7 == 0 ){ continue;}
						bits *= a7;
		
					}	
	
				}	
		}	
	}
	
	printf("\n");
}
