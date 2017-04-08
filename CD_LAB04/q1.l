%{
/*
TO EVALUATE A BOOLEAN EXPRESSION. EXAMPLE !0,0&&1,0||1
*/

#include "y.tab.h"
#include <stdio.h>
%}

digit (1|0)+
op "|"|"!"|"&"
%%

{digit}			{	yylval = atoi(yytext);	return EX;	}
{op}			{	return *yytext;				}
[\t] 			;
\n			{	return *yytext;				}
.
%%

int yywrap()
{
 return 0;
}
