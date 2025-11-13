// this file is the main for this tool
/* TREELS
   this tool is intended to help developers visualize the filestructure
   that they are navigating all around
   the intended outcome is to create a terminal embedded GUI that shows the
   filestructure something like this

        ---dir2
   dir1-|
        ---dir3
*/

#include <stdio.h>
#include <string.h>
#include <windows.h>

void use();
void help();


int main(int argc, char* argv[]) {

	// use double backslash to represent one backslash in C
	char directoryPath[] = "C:\\Users\\Gabe\\Desktop\\*";

	// instantiate struct to store files/dirs
	WIN32_FIND_DATA win_find_data;
	
	// handle is specfic to windows
	// handle specifies what resource we are pointing to
	// only on windows os
	HANDLE hFind = FindFirstFile(directoryPath, &win_find_data);

	if (hFind == INVALID_HANDLE_VALUE) {
		printf("Path not found\n");
		return 1;
	}

	// loop thru all files
	do { printf("%s\n", win_find_data.cFileName);
	} while (FindNextFile(hFind, &win_find_data) != 0);

	FindClose(hFind);
	return 0;
	

	/*
	Here is some potential help flag logic to make the command line UX better
	
	if(argc == 1) {
		use();
	}

	if(argc == 2) {
		if(strcmp(argv[1], "-h") == 0) {

			help();
		}
	}
	*/
}

void use() {
	printf("treels util. Type treels -h for more information\r\n");
}

void help() {
	printf("Type:\r\ntreels {dir}\r\nto print a tree for the dir.\r\n");
}
