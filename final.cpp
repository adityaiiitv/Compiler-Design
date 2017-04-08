#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;
char statement[100];
void arith()
{
	char op;
	int l=strlen(statement);
	cout<<"\n The statement entered is: "<<statement;
	int i=0,flag0=0,flag1=0,firstflag=0,secondflag=0;
	char first,second,third;
	while((flag0==0 || flag1==0) && i<=l)
	{
		if(firstflag==1 && secondflag==0)
		{
			if(isalpha(statement[i]))
			{
				second=statement[i];
				secondflag=1;
			}
		}
		if(firstflag==0)
		{
			if(isalpha(statement[i]))
			{
				first=statement[i];
				firstflag=1;
			}
		}
		if(statement[i]=='=' && flag0==0)
		{
			flag0=1;
		}
		if(flag0==1 && (statement[i]=='+' || statement[i]=='-' || statement[i]=='*' || statement[i]=='/'))
		{
			flag1=1;
			op=statement[i];
			cout<<"\n Case of arithmetic operations detected.\n";
		}
		i++;
	}
	int flag=0;
	i=l-1;
	while(flag==0)
	{
		if(isalpha(statement[i]))
		{
			third=statement[i];
			flag=1;
		}
		i--;
	}
			// Arithmetic detection complete
	if(flag1==1)
	{
		cout<<" LD R1, "<<second<<"\n";
		cout<<" LD R2, "<<third<<"\n";
		if(op=='+')
		{
			cout<<" ADD R1, R1, R2"<<"\n";
		}
		if(op=='-')
		{
			cout<<" SUB R1, R1, R2"<<"\n";
		}
		if(op=='*')
		{
			cout<<" MUL R1, R1, R2"<<"\n";
		}
		if(op=='/')
		{
			cout<<" DIV R1, R1, R2"<<"\n";
		}
		cout<<" STR "<<first<<", R1";
	}
}
int main()
{
	
	
	int choice=0,res;
		while(choice!=4)
	{
		cout<<" Enter the C statement without white spaces: ";
		cin.getline(statement,sizeof(statement));
		cout<<"\n Enter the type of statement to be inserted:\n (1) Arithmetic	(2) Assignment (3) Relational\n Press (4) to quit:";
		cin>>choice;
		if(choice==1)
		{
			
			arith();
			break;
		}
		if(choice==2)
		{
//		assign();
		}
		if(choice==3)
		{
	//		rel();
		}
		
	}
	return 0;
}
