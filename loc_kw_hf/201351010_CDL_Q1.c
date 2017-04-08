/* Aditya Prakash 201351010 */
#include<stdio.h>
#include<string.h>
int main()				// MAIN FUNCTION
{	
	FILE *fh,*fh1,*fh2;
	// Three file pointers
	int com_lines=0,i;
	// com_lines for number of commented lines
	char s[100];
	if ( ( fh = fopen( "CD_lab1.c", "r" ) ) == NULL )
	// Try to open a file with the help of file pointer fh.
	// First argument is the name of the file.
	// Second argument is the mode. In this case it is read mode.
	{
		printf( "File could not be opened\n" );
		// Print error message if cannot be opened.
	}
	while ( fgets ( s, 99, fh ) != NULL )
	{	// Read the file line by line till it ends.
		printf ( "%s" , s ) ;
		// commented lines
		// single comments
		for(i=0;i<strlen(s);i++)
		{
			// For every element of string
			if(s[i]=='/' && s[i+1]=='/')
			{
				com_lines++;							// SINGLE LINE COMMENTS ++
				// If an element is '/' and the next element is also the same
				// Then increment the number of commented lines.
			}
		}						
	}
	
	// For multi line comments
	if ( ( fh1 = fopen( "CD_lab1.c", "r" ) ) == NULL )
	{
		printf( "File could not be opened\n" );
	}
	int begin=0,j=0;	// Use begin as a flag, j is another iterator.
	while ( fgets ( s, 99, fh1 ) != NULL )
	{
		// Read every line
		if(begin==1)
		{
			// Check if multi line comment has begun.
			for(i=0;i<strlen(s);i++)
			{
				// For every element in the string.
				if(s[i]=='*' && s[i+1]=='/')
				{
					// If an element is * and the next element is /
					printf ( "%s" , s ) ;
					begin = 0;
					// Then multi line comment has ended. Set begin to zero again.
					com_lines++;
					// Add to the number of commented lines
				}
			}
			if(begin == 1)
			{
				// If multi line comment has started
				printf ( "%s" , s ) ;
				com_lines++;
				// Add to com_lines.
			}
		}
		
		if(begin==0)
		{
			// If it has not begin yet
			for(i=0;i<strlen(s);i++)
			{
				if(s[i]=='/' && s[i+1]=='*')
				{
					// If an element is / and the next is  *
					j=i;
					// Change the iterator accordingly.
					begin = 1;
					// Set the flag
				}
			}
			if(begin == 1)
			{
				printf ( "%s" , s ) ;
				com_lines++;
				// If it has started then add to com_lines
			}
			for(i=j;i<strlen(s);i++)
			{
				// Check for */ in the same line.
				if(s[i]=='*' && s[i+1]=='/')
				{
					begin = 0;
					// If found, change the begin flag.
				}
			}
		}
		
	}															// LOGIC FOR MULTI LINE COMMENTS END
	// for executable lines
	if ( ( fh2 = fopen( "CD_lab1.c", "r" ) ) == NULL )
	{
		// Use another file handler for executable lines.
		printf( "File could not be opened\n" );
	}
	int exe_lines=0;// To count the same
	while ( fgets ( s, 99, fh2 ) != NULL )
	{
		for(i=0;i<strlen(s);i++)
		{
			if(s[i]=='\n')
			{
				// If the line has \n
				exe_lines++;
				// Increment the count.
			}
		}
		if(strlen(s)==2)
		{
			exe_lines--;
		}
	}
	// Find the actual number of lines
	exe_lines = exe_lines-com_lines;
	// By subtracting the number of commented lines.
	// commented lines code end
	fclose ( fh ) ;
	fclose ( fh1 ) ;
	fclose ( fh2 ) ;
	// Close all the file handlers.
	printf("\n The total number of commented lines in the code: %d", com_lines);
	printf("\n The total number of executable lines in the code: %d", exe_lines);
	return 0;
}
// END OF CODE
