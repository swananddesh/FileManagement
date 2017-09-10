/*
	Write a program which accept file name from user and print all
	information about that file.

	Input :- Filename
	Output :- File information of given file.

*/

#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

int main()
{
	int returnValue;
	struct stat fileStat;

	char fileName[100];

	printf("Enter file name : ");
	scanf("%s", fileName);

	// stat function accept file name as a parameter
	returnValue = stat(fileName, &fileStat);
	if(returnValue == -1)
	{
		printf("stat function fail\n");
		return -1;
	}

	printf("Size of File : \t\t%d bytes\n",(int)fileStat.st_size);
	printf("Number of Links : \t%d\n",(int)fileStat.st_nlink);
	printf("File inode : \t\t%d\n",(int)fileStat.st_ino);
	printf("File system number: \t\t%d\n",(int)fileStat.st_dev);
	printf("Number of blocks allocated for file\t\t%d\n",(int)fileStat.st_blocks);
	printf("File Permissions: \t");

	printf( (S_ISDIR(fileStat.st_mode))  ? "d" : "-");
	printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
	printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
	printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
	printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
	printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
	printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
	printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
	printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
	printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
	printf("\n\n");
 
	if(S_ISLNK(fileStat.st_mode))
	{
		printf("It is symbolic link\n");
	}
	else
	{
		printf("It is not symbolic link\n");
	}

	return 0;
}