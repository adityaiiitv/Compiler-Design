%{

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define YYSTYPE int

%}

%left '-' '+' '*' '/'
%token num

%%
statement:	expression 				{	printf("\n");	}
							;
	
expression:	expression '-' expression		{	printf("-");		}
		|expression '+' expression		{	printf("+");		}
		|expression '/' expression		{	printf("/");		}
		|expression '*' expression		{	printf("*");		}
		|'(' expression ')'			{	$$ = $1;		}
							;
		|term					;

term:		num					{	printf("%d ", $$);	}
							;
%%

int main()	// MAIN FUNCTION
{
	printf("\n Enter digits from 0-9 and operators in infix notation.");
	yyparse();
	return 0;
}

yyerror (s)	// CALLED ON ERROR
char *s;
{
	printf ("%s\n", s);
}
