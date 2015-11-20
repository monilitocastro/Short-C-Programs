//MONILITO CASTRO HW9
//Some of this source is borrowed http://stackoverflow.com/questions/3554120/open-directory-using-c
#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main (int c, char *v[]) {
        struct dirent *pointerFolderent;
	DIR *pointerFolder;

        if (c < 2) {
            	printf ("Usage: testprog <dirname>\n");
            	return 1;
        }
        pointerFolder = opendir (v[1]);
        if (pointerFolder == 0) {
            	printf ("Directory error (cannot open): '%s'\n", v[1]);
            	return 1;
        }
	while ((pointerFolderent = readdir(pointerFolder)) != NULL) {
		if(     strcmp(pointerFolderent->d_name, "..")==0 ||
		        strcmp(pointerFolderent->d_name, ".")==0){
			continue;		
		}
       	     	printf ("%s\n", pointerFolderent->d_name);
        }

        closedir (pointerFolder);
        return 0;
    }
