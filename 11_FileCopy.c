/*
	Write a program which accept two file names from user and copy the
	contents of an existing file into newly created file.

	Input :- 2 file names as source file and destination file
	Output :- Source file content will get copied into destination file.
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *source, *target;
	char ch;

	source = fopen(argv[1], "r");

	if (source == NULL)
	{
		printf("Unable to open file : \n", argv[1]);
		return -1;
	}

	target = fopen(argv[2], "w");

	if (target == NULL)
	{
		fclose(source);
		printf("Target file not found\n");
		return -1;
	}

	while((ch = fgetc(source)) != EOF)
		fputc(ch, target);

	printf("File copied successfully\n");
	fclose(source);
	fclose(target);
	return 0;
}