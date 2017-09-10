/*
	Write a program which accept file name and number of bytes from
	user and read that number of bytes from file.

	Input :- file name, no. of bytes
	Output :- file content that have specified as no. of bytes

	Library funcion used:
	fread()

	Syntax:
	fread(void *ptr, size_t size, size_t stringSize, FILE *fp);

	where,
	ptr = Pointer to the array of elements to be read.
	size = Size in bytes of each element to be read.
	stringSize =  Number of elements, each one with a size of stringSize bytes.
	fp = Pointer to a FILE object that specifies an input stream.
*/

#include <stdio.h>

int main()
{
	char fileName[100];
	char fileContent[100];
	int bytes;
	FILE *fp;

	printf("Enter file name : \n");
	scanf("%s", fileName);

	printf("Enter no. of bytes to be read : \n");
	scanf("%d", &bytes);

	fp = fopen(fileName, "r");

	if (fp == NULL)
	{
		printf("Could not open file\n");
	}

	fread(fileContent, bytes, 1, fp);
	printf("%s\n", fileContent);
	fclose(fp);
	return 0;
}