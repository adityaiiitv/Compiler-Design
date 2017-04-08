/*	TITLE:	COMPILER DESIGN LAB EXAM
 * 	AUTHOR:	ADITYA PRAKASH
 * 	ID:		201351010
 */
#include<iostream>
#include<string.h>	// FOR STRING OPERATIONS.
#include<ctype.h>	// FOR CHARACTER OPERATIONS.
#include<stdlib.h>	// FOR CLEARING THE SCREEN, NOT USED INITIALLY.
using namespace std;// STANDARD NAMESPACE.
int main()			// MAIN FUNCTION.
{
	char statement[100];	// Statement IS TAKEN FROM THE USER AND CORRESPONDING CODE IS CREATED.
	cout<<"\n\n Enter the C statements to get the assembly code. Enter type exit to end the session.\n Sample inputs: x=y+z , if x<y goto R , b=a[8] \n\n ";
	cin.getline(statement,sizeof(statement));	// GET THE INPUT WITH WHITE SPACES TOO.
	while(statement[0]!='e' && statement[1]!='x' && statement[2]!='i' && statement[0]!='3')	// TYPE exit TO FINISH.
	{
		cout<<" _______________\n";
		//cout<<"\n\n ";
		//system("clear");
		int l=strlen(statement);		// THE LENGTH OF THE INPUT.
		int i=0,flagequal=0,flagop=0;	// flagequal CHECKS THE PRESENCE OF '=', flagop CHECKS THE PRESENCE OF ANY OPERATOR.
		int case0=0,case1=0,case2=0;	// THE STATEMENT IS DIVIDED INTO 3 CASES:- ASSIGNMENT, ARITHMETIC AND RELATIONAL.
		char first,second,third,op;		// RETRIEVE THE VARIABLES AND STORE THEM IN first, second AND third.
		int flagfirst=0,flagsecond=0,flagthird=0;	// TO CHECK THE PRESENCE OF first, second AND third.
		// CASE: ARITHMETIC
		while(flagop==0 && i<l)	// WORK TILL OPERATOR IS DETECTED AND THE LENGTH IS NOT EXCEEDED.
		{
			if(flagfirst==0)	// IF FIRST IS NOT FOUND.
			{
				if(isalpha(statement[i]))	// CHECK FOR ALPHABET.
				{
					first=statement[i];		// GET first.
					flagfirst=1;			// MODIFY THE FLAG.
				}
			}
			if(flagequal==1 && flagsecond==0)	// IF EQUAL SYMBOL IS THERE AND SECOND IS NOT DETECTED.
			{
				if(isalpha(statement[i]))	// CHECK FOR ALPHABET.
				{
					second=statement[i];	// GET second.
					flagsecond=1;			// MODIFY THE FLAG.
				}
			}
			if(flagequal==1 && flagop==0)	// IF EQUAL SYMBOL IS FOUND AND OPERATOR IS NOT FOUND YET.
			{
				if(statement[i]=='+' || statement[i]=='-' || statement[i]=='*' || statement[i]=='/')	// LOOK FOR OPERATOR.
				{
					op=statement[i];		// GET OPERATOR.
					flagop=1;				// MODIFY FLAG.
					//cout<<"\n Arithmetic case detected.\n";
					case0=1;				// CONFIRM THAT IT IS CASE 0 : ARITHMETIC.
				}
			}
			if(statement[i]=='=' && flagequal==0)	// CHECK FOR EQUAL SYMBOL.
			{
				flagequal=1;				// MODIFY THE FLAG.
			}
			i++;							// INCREMENT THE ITERATOR.
		}
		i=l-1;								// SET TO THE END OF THE STRING.
		if(case0==1)						// CHECK IF CASE 0.
		{
			while(flagthird==0)				// IF third IS NOT FOUND.
			{
				if(isalpha(statement[i]))	// CHECK IF ALPHABET.
				{
					third=statement[i];		// GET third.
					flagthird=1;			// MODIFY THE FLAG.
				}
				i--;						// IF NOT FOUND THEN DECREMENT THE POINTER.
			}
		}
		if(case0==1)						// CHECK IF CASE 0.
		{
			cout<<" LD R1, "<<second<<"\n";
			cout<<" LD R2, "<<third<<"\n";
			if(op=='+')		// CHECK FOR +
			{
				cout<<" ADD R1, R1, R2"<<"\n";
			}
			if(op=='-')		// CHECK FOR -
			{
				cout<<" SUB R1, R1, R2"<<"\n";
			}
			if(op=='*')		// CHECK FOR *
			{
				cout<<" MUL R1, R1, R2"<<"\n";
			}
			if(op=='/')		// CHECK FOR /
			{
				cout<<" DIV R1, R1, R2"<<"\n";
			}
			cout<<" STR "<<first<<", R1";
		}
		// ARITHMETIC CASE ENDS.
		
		// ASSIGNMENT CASE BEGINS. CASE 1.
		flagfirst=0,flagsecond=0,flagthird=0;	// SET ALL FLAGS TO ZERO AGAIN.
		if(case0==0)				// IF PREVIOUS CASE IS NOT DETECTED.
		{
			flagequal=0;i=0;int flagbopen=0,flagbclose=0;	// flagbopen FOR [ , flagbclose FOR ].
			while(flagbclose==0 && i<l)		// WORK TILL B CLOSE IS NOT FOUND AND LENGTH IS NOT EXCEEDED.
			{
				if(flagfirst==0)	// IF FIRST ELEMENT IS NOT FOUND.
				{	
					if(isalpha(statement[i]))	// CHECK IF ALPHABET.
					{
						first=statement[i];		// GET first.
						flagfirst=1;			// MODIFY THE FLAG.
					}
				}
				if(flagbopen==1 && flagsecond==0)	// IF ] IS FOUND BUT second IS NOT FOUND YET.
				{
					if(isalpha(statement[i]))	// CHECK IF ALPHABET.
					{
						second=statement[i];	// GET second.
						flagsecond=1;			// MODIFY THE FLAG.
					}
				}
				if(flagbopen==1 && statement[i]==']')	// [ IS FOUND AND CHECK FOR ]
				{
					flagbclose=1;	// MODIFY THE FLAG IF FOUND.
					case1=1;		// CONFIRM CASE 1.
					//cout<<"\n Assignment case detected.\n";
				}
				if(flagequal==1 && statement[i]=='[')	// IF EQUAL SYMBOL FOUND , SEARCH FOR [
				{
					flagbopen=1;	// MODIFY THE FLAG.
				}
				if(statement[i]=='=' && flagequal==0)	// SEARCH FOR = SYMBOL.
				{
					flagequal=1;	// MODIFY THE FLAG.
				}
				i++;				// INCREMENT THE ITERATOR.
			}
		}
		if(case1==1)			// CHECK IF CASE 1.
		{
			while(flagthird==0)	// IF THIRD IS NOT FOUND.
			{
				if(isdigit(statement[i]))	// CHECK IF A DIGIT.
				{
					third=statement[i];		// GET third.
					flagthird=1;			// MODIFY THE FLAG.
				}
				i--;			// DECREMENT TILL NOT FOUND.
			}
		}
		if(case1==1)			// OUTPUT IN THE CASE.
		{
			cout<<"\n";
			cout<<" LD R1, "<<third<<"\n";
			cout<<" MUL R1, R1, 8\n";
			cout<<" LD R2, "<<second<<"(R1)\n";
			cout<<" STR "<<first<<", R2";
		}
	//	ASSIGNMENT CASE ENDS.
	
	//	RELATIONAL CASE BEGINS.
		flagfirst=0,flagsecond=0,flagthird=0;	// SET ALL THE FLAGS TO ZERO.
		if(case0==0 && case1==0)				// IF NOT CASE 0 OR CASE 1.
		{
			int flagrel=0,flagif=0,flaggoto=0;i=0;	// flagrel FOR RELATIONAL OPERATOR, flaggoto FOR goto KEYWORD.
			while(flaggoto==0 && i<l)	// WORK TILL flaggoto IS NOT FOUND AND LENGTH IS NOT EXCEEDED.
			{
				if(flagrel==1)			// IF A RELATION IS FOUND.
				{
					if(statement[i-1]==' ' && statement[i]=='g' && statement[i+1]=='o' && statement[i+2]=='t' && statement[i+3]=='o' && statement[i+4]==' ')
					{					// CHECK FOR goto KEYWORD.
						flaggoto=1;		// MODIFY THE FLAG.
						case2=1;		// CONFIRM CASE 2.
						//cout<<"\n Relation case detected.\n";
						break;
					}
				}
				if(flagrel==1 && flagsecond==0)	// IF A RELATION IS FOUND AND second IS NOT FOUND YET.
				{
					if(isalpha(statement[i]))	// CHECK FOR ALPHABET.
					{
						second=statement[i];	// GET second.
						flagsecond=1;			// MODIFY THE FLAG.
					}
				}
				if(flagif==1 && flagfirst==0)	// IF if IS DETECTED AND first IS NOT FOUND YET.
				{
					if(isalpha(statement[i]))	// CHECK FOR ALPHABETS.
					{
						first=statement[i];		// GET first.
						flagfirst=1;			// MODIFY THE FLAG.
					}
				}
				if(flagif==1)		// IF if IS FOUND.
				{
					if(statement[i]=='<' || statement[i]=='>')	// CHECK FOR A RELATION.
					{
						flagrel=1;	// MODIFY THE FLAG.
						op=statement[i];	// GET THE RELATION AS op.
					}
				}
				if(flagif==0)		// IF is IS NOT FOUND YET.
				{
					if(statement[i-1]=='i' && statement[i]=='f' && statement[i+1]==' ')	// CHECK FOR IF.
					{
						flagif=1;	// MODIFY THE FLAG.
					}
				}
				i++;				// INCREMENT THE ITERATOR.
			}
		}
		i=l-1;						// SET i TO LAST OF THE STRING.
		if(case2==1)				// IF CASE 2 IS TRUE.
		{
			while(flagthird==0)		// IF third IS NOT FOUND YET.
			{
				if(isalpha(statement[i]))	// CHECK FOR ALPHABET.
				{
					third=statement[i];		// GET third.
					flagthird=1;			// MODIFY THE FLAG.
				}
				i--;				// DECREMENT TILL NOT FOUND.
			}
		}
		if(case2==1)				// IF CASE 2 IS TRUE.
		{
			cout<<"\n";
			cout<<" LD R1, "<<first<<"\n";
			cout<<" LD R2, "<<second<<"\n";
			if(op=='<')		// CHECK FOR <
			{
				cout<<" SUB R1, R1, R2"<<"\n";
			}
			if(op=='>')		// CHECK FOR >
			{
				cout<<" SUB R1, R2, R1"<<"\n";
			}
			cout<<" BLTZ R1, "<<third;
		}
		if(case1==0 && case2==0 && case0==0)	// IF NONE OF THE CASES ARE TRUE.
		{
			cout<<"\n Unexpected case. Try again.\n";	// ERROR.
		}
		cout<<"\n\n ";
		cin.getline(statement,sizeof(statement));	// GET THE INPUT WITH WHITE SPACES TOO.
	}
	return 0;
}
/*	END OF PROGRAM	*/
