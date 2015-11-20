//MONILITO CASTRO HW9
//Some of this source is borrowed from http://stackoverflow.com/questions/3554120/open-directory-using-c
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main (int c, char *v[]) {
        struct dirent *pointerFolderent;
	DIR *pointerFolder;
	FILE * stdout;
        stdout = fopen("stdout1.txt", "w");
        
        /*
        if (c < 2) {
            	printf ("Usage: testprog <dirname>\n");
            	return 1;
        }*/
        char dirName[] = "./";
        pointerFolder = opendir (dirName);
        if (pointerFolder == 0) {
            	printf ("Directory error (cannot open): '%s'\n", v[1]);
            	return 1;
        }
	while ((pointerFolderent = readdir(pointerFolder)) != NULL) {
		if(     strcmp(pointerFolderent->d_name, "..")==0 ||
		        strcmp(pointerFolderent->d_name, ".")==0){
			continue;		
		}
       	     	fputs(pointerFolderent->d_name, stdout );
       	     	
       	     	fputs("\n", stdout );
        }

        closedir (pointerFolder);
        fclose(stdout );
        system("sort stdout1.txt > stdout2.txt");
        system("head -1 stdout2.txt; tail -1 stdout2.txt");
        system("rm stdout1.txt  stdout2.txt");
        
        
        return 0;
    }
