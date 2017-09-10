/*
	Write a program which accept directory name from user and print all
	file names and its types from that directory.

	Input :- Directory name
	Output :- files names with their types within that directory
*/

#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	DIR *dir;
	struct dirent *info;
	struct stat fileTypeInfo;
	char directoryName[100];
	char buffer[256];

	

	
	if ((dir = opendir(argv[1])) == NULL)
	{
		printf("Unable to open specified directory\n");
		return -1;
	}

	 
	while((info = readdir(dir)) != NULL)
	{
		
		sprintf(buffer, "%s/%s", argv[1], info->d_name);
	
		
		if (stat(buffer,&fileTypeInfo) < 0)
		{
			return -1;
		}
		
		if (S_ISREG(fileTypeInfo.st_mode))
		{
			printf("File Name :%s \t", info->d_name);
			printf("\t Regular file\n");
		}
		else if (S_ISDIR(fileTypeInfo.st_mode))
		{
			printf("File Name : %s\t", info->d_name);
			printf("\t Directory\n");
		}
		else if (S_ISCHR(fileTypeInfo.st_mode))
		{
			printf("File Name : %s\t", info->d_name);
			printf("Character special fiel\n");
		}
		else if (S_ISBLK(fileTypeInfo.st_mode))
		{
			printf("File Name : %s\t", info->d_name);
			printf("Block special file\n ");
		}
		else
		{
			printf("File type is unknown\n");
		}
	}
	closedir(dir);
	printf("\n");
	return 0;
	
}