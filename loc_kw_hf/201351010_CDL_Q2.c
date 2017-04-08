/* Aditya Prakash 201351010 */
#include<stdio.h>	
#include<string.h>
int main()			// MAIN FUNCTION
{	
	FILE *fh;
	int i;
	char s[100];
	if ( ( fh = fopen( "CD_lab1.c", "r" ) ) == NULL )		// OPEN THE FILE
	{
		printf( "File could not be opened\n" );
	}
	while ( fgets ( s, 99, fh ) != NULL )					// INPUT THE CONTENTS AS A STRING ONE BY ONE AS A LINE
	{	
		int j=0;
		//printf ( "%s" , s ) ;
		// header files
		for(i=0;i<strlen(s);i++)
		{
			if(s[i]=='#' && s[i+1]=='i' && s[i+2] == 'n')	// SEARCHING FOR #include
			{
				j=i+9;
			}
		}
		if(j!=0)
		{
			for(i=j;s[i]!='>';i++)
			{
				printf("%c",s[i]);
			}
			printf("\n");									// REMOVING '<' AND '>' AND PRINTING THE FILE NAME
		}
			
	}
	fclose ( fh ) ;											// CLOSING THE FILE POINTER
	return 0;
}
// END OF CODE
