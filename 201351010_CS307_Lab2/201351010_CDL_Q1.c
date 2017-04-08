// Author : Aditya Prakash
#include<stdio.h>
#include<string.h>	// FOR STRING OPERATIONS
#include<ctype.h>	// FOR CHARACTER OPERATIONS

int main()			// MAIN FUNCTION
{
	char input[30];	// STRING TO INPUT
	int i=0;		// TO ITERATE
	
	printf("\n Enter the string without any spaces in between: ");
	scanf("%s",input);
	printf("\n Input is: %s",input);
	printf("\n");
	int l= strlen(input);	// LENGTH OF INPUT
	
	while(i!=l)				// TILL LENGTH IS NOT CONSUMED
	{
		if(input[i]=='i' && input[i+1]=='f')	// SEARCH FOR if
		{
			printf("\n IF : <1,1>");
			i+=2;								// SKIP STRING BY 2 CHARACTERS
		}
		
		int len=0;char var[10];					// LOOK FOR VARIABLES
		if(isalpha(input[i]))
		{
			len=i;
			int iter=0;
			while(isalpha(input[len]))			// COMPARE TO ALPHABET
			{
				var[iter]=input[len];
				len++;iter++;
			}
		}
		if(len!=0)
		{
			printf("\n %s : %p",var,input[i]);
			i=len;
		}
		
		if(input[i]<58 && input[i]>47)			// SEARCH FOR A NUMBER IN ASCII
		{
			int temp=input[i]-48;
			printf("\n numeric-constant %d : <3,%p>",temp,input[i]);
			i++;
		}
		
		if(input[i]==';')						// SEARCH FOR ;
		{
			i++;
			printf("\n ; : <4,4>");
		}
		
		if(input[i]=='(')						// SEARCH FOR (
		{
			i++;
			printf("\n ( : <5,0>");
		}
		
		if(input[i]==')')						// SEARCH FOR )
		{
			i++;
			printf("\n ) : <5,1>");
		}
		
		if(input[i]=='{')						// SEARCH FOR {
		{
			i++;
			printf("\n { : <6,0>");
		}
		
		if(input[i]=='}')						// SEARCH FOR }
		{
			i++;
			printf("\n } : <6,1>");
		}
		
		if(input[i]=='>')						// SEARCH FOR >
		{
			i++;
			printf("\n > : <62,62>");
		}
		
		if(input[i]=='<')						// SEARCH FOR <
		{
			i++;
			printf("\n < : <60,60>");
		}
		
		if(input[i]=='!')						// SEARCH FOR !
		{
			i++;
			printf("\n ! : <33,33>");
		}
		
		if(input[i]=='=')						// SEARCH FOR =
		{
			i++;
			printf("\n = : <61,61>");
		}
		
		if(input[i]=='>' && input[i+1]=='=')	// SEARCH FOR >=
		{
			i+=2;
			printf("\n >= : <620,620>");
		}
		
		if(input[i]=='<' && input[i+1]=='=')	// SEARCH FOR <=
		{
			i+=2;
			printf("\n <= : <600,600>");
		}
		
		if(input[i]=='=' && input[i+1]=='=')	// SEARCH FOR ==
		{
			i+=2;
			printf("\n == : <610,610>");
		}
		
		if(input[i]=='!' && input[i+1]=='=')	// SEARCH FOR !=
		{
			i+=2;
			printf("\n != : <330,330>");
		}
		
	}
	return 0;	// RETURN FROM MAIN FUNCTION
}
// END OF PROGRAM
