/*
	Write program which accept directory name from user and delete all
 	empty files from that directory.

 	Input :- Directory name
 	Output :- Empty files will be deleted within the given directory.
*/

#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	DIR *dir;
	struct stat fileStat;
	struct dirent *entry;
	char buffer[256];
	int returnValue;
	int fileSize;
	int status;

	if ((dir = opendir(argv[1])) == NULL)
	{
		printf("Unable to open specified directory\n", errno);
	}

	while((entry = readdir(dir)) != NULL)
	{
		sprintf(buffer,"%s/%s",argv[1],entry->d_name);
		returnValue = stat(buffer, &fileStat);
		if (returnValue == -1)
		{
			printf("stat function fail\n", errno);
			return -1;
		}

		fileSize = (int) fileStat.st_size;
		if (fileSize == 0)
		{
			unlink(buffer);
		}
	}

	printf("Empty files deleted successfully\n");

	return 0;
}