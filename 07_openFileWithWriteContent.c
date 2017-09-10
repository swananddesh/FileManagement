/*
	Write a program which accept file name from user and write string in that file.

	input :- path name for specified file to open
	output :- file will be opened and will write some content to the file.

	Library funcion used:
	fwrite()

	Syntax:
	fwrite(const void *ptr, size_t size, size_t stringSize, FILE *fp);

	where,
	ptr = Pointer to the array of elements to be written.
	size = Size in bytes of each element to be written.
	stringSize =  Number of elements, each one with a size of stringSize bytes.
	fp = Pointer to a FILE object that specifies an output stream.
*/

#include <stdio.h>

int main()
{
	FILE *fp;
	char fileName[100];
	char stringToBeWritten[100] = "Hello World, I am learning Multi OS Programming";
 
	printf("\n Enter file name : ");
	scanf("%s", fileName);

	fp = fopen(fileName, "w");

	if (fp == NULL)
	{
		perror("\n Could not open specified file\n");
	}

	fwrite(stringToBeWritten, 1, sizeof(stringToBeWritten), fp);
	fclose(fp);

	return(0);
}