/*
	Write a program which accept file name from user and open that file

	input :- path name for specified file to open
	output :- file will be opened
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;

			if ( argc != 2 ) /* argc should be 2 for correct execution */
    	{
        	/* We print argv[0] assuming it is the program name */
        	printf("\n Please provide filename.", argv[0]);
    	}
        // We assume argv[1] is a filename to open
        fp = fopen(argv[1], "r");

        /* fopen returns 0, the NULL pointer, on failure */
        if (fp == 0)
        {
            perror("Could not open file\n");
        }
        else
        {
            printf("File Successfully Opened\n");
            fclose( fp );
        }
    return 0;
}