// Author : Aditya Prakash
/*
 * SOME IMPORTANT NOTES TO CONSIDER / ASSUMPTIONS / IMPLICATIONS:
 * (1) NULL SYMBOL : '@'
 * (2) EACH PRODUCTION MUST START AND END WITH A '|'. THE SAME HAS TO BE USED AS A SEPARATOR
 * 	   Example : |A|B|c|d|@|
 * (3) IN CASE OF |NONTERMINAL........| ONLY THE PRODUCTION WITH DEPENDENCY IS MENTIONED AND NOT THE NON TERMINALS
 *     Example : P0 : S -> |A|B|C|
 * 				 P1 : A -> |B|
 * 				 P2 : B -> |A|
 * 				 P3 : C -> |@|
 * 	   Output : Production P1 : Production P2 non terminals are also there
 * 				Production P2 : Production P1 non terminals are also there
 * (4) IF THE LAST PRODUCTION RULE HAS DEPENDENCY, PLEASE IGNORE THE REDUNDANT DISPLAY IF ANY
*/
#include<stdio.h>
#include<string.h>	// FOR STRING OPERATIONS
#include<ctype.h>	// FOR CHARACTER OPERATIONS

int main()			// MAIN FUNCTION
{
	int i,j,k,q;
	printf("\n Enter the number of non terminals including the starting symbol: ");
	int nt;				// THE NUMBER OF NON TERMINALS
	scanf("%d",&nt);	// INPUT THE NUMBER OF NON TERMINALS
	char nonterm[nt];	// AN ARRAY FOR STORING NON TERMINALS
	char prod[nt][10];	// A MATRIX FOR STORING THE PRODUCTION RULES
	for(i=0;i<nt;i++)	// FOR INPUT OF THE NON TERMINALS AND THE PRODUCTION RULES
	{
		printf("\n Enter non terminal number %d:",i);
		scanf("%1s",&nonterm[i]);	// INPUT NON TEMRINAL
		printf("\n Enter the production rules with | to separate. Also use the same to start and end the productions. Use @ in place of null.\n");
		scanf("%s",&prod[i]);		// ENTER THE PRODUCTIONS WITH THE INSTRUCTIONS GIVEN
	}
	char buffer[nt][10];			// TO STORE THE DEPENDENCIES
	for(i=0;i<nt;i++)			// TO ITERATE OVER EACH NON TERMINAL
	{
		int buf=0;					// buffer[][] ITERATOR
		for(j=0;j<strlen(prod[i]);j++)	// TO ITERATE IN THE PRODUCTIONS
		{
			if(isupper(prod[i][j]) && prod[i][j-1]=='|')	// IN CASE OF |A....
			{
				buffer[i][buf]=prod[i][j];		// FILL THE DEPENDENCIES
				buf++;							// ITERATE
			}
			if(islower(prod[i][j]) && prod[i][j-1]=='|' && prod[i][j+1]=='|')		// IN CASE OF |a|
			{
				printf("\n Production %d: %c",i,prod[i][j]);
			}
			if(islower(prod[i][j]) && prod[i][j-1]=='|' && isupper(prod[i][j+1]))	// IN CASE OF |aA....
			{
				printf("\n Production %d: %c",i,prod[i][j]);
			}
			if(prod[i][j]=='@' && prod[i][j-1]=='|' && prod[i][j+1]=='|')			// IN CASE OF NULL SYMBOL 
			{
				printf("\n Production %d: %c",i,prod[i][j]);
			}
		}
		
										// FOR HANDLING DEPENDENCIES
			for(q=0;q<buf;q++)		// TO ITERATE OVER EACH BUFFER LENGTH
			{
				if(isupper(buffer[i][q]))				// IF AN UPPER CASE ALPHABET
				{
					for(k=0;k<nt;k++)				// ITERATE OVER ALL PRODUCTIONS
					{
						int flag=0;
						if(buffer[i][q]==nonterm[k])	// CONFIRM DEPENDENCY
						{
							if(i!=k)					// NOT IN THE SAME PRODUCTION OFCOURSE
							{
								if(k!=nt-1)				// AVOID REDUNDANT DISPLAY
								{
									printf("\n Production %d: Production %d terminals are also there",i,k);
								}
								if(k==nt-1 && flag==0)	// AVOID REDUNDANT DISPLAY
								{
									flag==1;
									printf("\n Production %d: Production %d terminals are also there",i,k);
								}
							}
						}
					}
					// printf("\n checking %c",buffer[i][j]);
				}
			}
		
		
	}
	return 0;	// RETURN FROM MAIN FUNCTION
}
// END OF PROGRAM
