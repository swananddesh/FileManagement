/*
	Write a program which accept directory name from user and print all
	file names from that directory.

	Input :- Directory name
	Output :- List of files within directory
*/

#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>

int main()
{
	DIR *dir;
	struct dirent *info;

	char directoryName[100];

	printf("\n Enter directory name : ");
	scanf("%s", directoryName);

	if ((dir = opendir(directoryName)) == NULL)
	{
		printf("Unable to open specified directory\n", errno);
	}

	printf("List of files in the given directory are \n");

	// Here readdir() system call is used to read directory contents. 
	// It will return NULL on reaching end of directory
	while((info = readdir(dir)) != NULL) 
	{
		printf("File Name : %s\t", info -> d_name);
	}

	closedir(dir);
	return 0;
}

