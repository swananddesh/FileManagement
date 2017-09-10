/*
	Write a program which accept file name from user and read whole file.

	input :- path name for specified file to open
	output :- file will be opened and will display contents of the file.
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
            int x;
            /* 
            	Read one character at a time from file, stopping at EOF, which
               	indicates the end of the file.
            */
            while  ((x = fgetc(fp)) != EOF)
            {
                printf( "%c", x );
            }
            fclose( fp );
        }
    return 0;
}