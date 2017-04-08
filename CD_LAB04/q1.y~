%{
#include<stdio.h>
#include<ctype.h>
%}

%right '!'
%left '|' '&'
%token EX

%%
input:	input state '\n'		{	printf(" Answer : %d\n",$2);	}
	| error '\n'			{	printf("\n Invalid Syntax \n");	}
	|
	;

state:	EX				{	$$ = $1;			}	
	|state '|''|' EX		{	$$ = $1 || $4;			}
	|state '&''&' EX		{	$$ = $1 && $4;			} 
	| '!' state			{	$$ = ! $2;			}
	;
%%

int main()	// MAIN FUNCTION
{
	printf("\n Please enter the Boolean expression in the form of\n (op&&op , op||op, !op) where op can be either 0 or 1:\n ");
	yyparse();
}

int yyerror(char *s)	// IN CASE OF ERROR
{
	printf("\n%s",s);
}
