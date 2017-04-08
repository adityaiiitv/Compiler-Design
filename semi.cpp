#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;
int main()
{
	char statement[100],op;
	cout<<" Enter the C statement without white spaces: ";
	cin.getline(statement,sizeof(statement));
	int l=strlen(statement);
	cout<<"\n The statement entered is: "<<statement;

	//	b=a[i] CASE
	char number;
	int flag2=0;char second;char first;
	int flag0=0,flag1=0,i=0,firstflag=0,secondflag=0;
	while((flag0==0 || flag1==0))// && (case0==0 && case1==0))
	{
		if(flag0==1 && secondflag==0)
		{
			if(isalpha(statement[i]))
			{
				second=statement[i];
			}
			secondflag=1;
		}
		if(firstflag==0)
		{
			if(isalpha(statement[i]))
			{
				first=statement[i];
				firstflag=1;
			}
		}
		if(flag1==1 && statement[i]==']' && flag2==0)
		{
			flag2=1;
			cout<<"\n Array assignment case detected. Example: b=a[i]";
		}
		if(flag0==1 && statement[i]=='[' && flag1==0)
		{
			flag1=1;
			//cout<<"\n Array assignment case detected. Example: b=a[i]";
		}
		if(statement[i]=='=' && flag0==0)
		{
			flag0=1;
		}
		i++;
	}
	int flag=0;
	i=l-1;
	while(flag==0 && i>0)
	{
		if(isdigit(statement[i]))
		{
			number=statement[i];
			flag=1;
		}
		i--;
	}
	// DETECTION COMPLETE
//	if(/*case1==0 && case0==0*/)
	//{
		cout<<"\n";
		cout<<" LD R1, "<< number <<"\n";
		cout<<" MUL R1, R1, 8\n";
		cout<<" LD R2, "<<second<<"(R1)\n";
		cout<<" STR "<<first<<", R2";
//	}



// jhaad
	//	b=a[i] CASE COMPLETE
	int f0,f1,case0=0,donefir=0,donesec=0;
	f0=0;int j=0;f1=0;int f2=0;
	char relation,fir,sec;
	while(f2==0)
	{
		if(f0==1 && donefir==0)
		{
			if(isalpha(statement[j]))
			{
				fir=statement[j];
				donefir=1;
			}
		}
		if(f1==1 && donesec==0)
		{
			if(isalpha(statement[j]))
			{
				sec=statement[j];
				donesec=1;
				f2=1;
			}
		}
		if(f1==0 && f0==1)
		{
			if(statement[j]=='<' || statement[j]=='>')
			{
				relation=statement[j];
				f1=1;
				cout<<"\n Relation Case Detected.\n";
				case0=1;
			}
		}
		if(f0==0)
		{
			if(statement[j-1]=='i')
			{
				if(statement[j]=='f')
				{
					f0=1;
				}
			}
		}
		j++;
	}
	j=l-1;int d=0;char gotoname;
	while(d==0)
	{
		if(isalpha(statement[j]))
		{
			gotoname=statement[j];
			d=1;
		}
	}
	if(case0==1)
	{
		cout<<"\n";
		cout<<" LD R1, "<<fir<<"\n";
		cout<<" LD R2, "<<sec<<"\n";
		if(relation=='<')
		{
			cout<<" SUB R1, R1, R2"<<"\n";
		}
		if(relation=='>')
		{
			cout<<" SUB R1, R2, R1"<<"\n";
		}
		cout<<" BLTZ R1, "<<gotoname;
		
	}
	//	Relational case detected. Example:if x<y goto L
	

	//	for type x = y - z
	i=0,flag0=0,flag1=0,firstflag=0,secondflag=0;
	while((flag0==0 || flag1==0) && i<=l && case0==0)
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
	flag=0;
	i=l-1;
	char third;
	while(flag==0)
	{
		if(isalpha(statement[i]))
		{
			third=statement[i];
			flag=1;
		}
		i--;
	}
	int case1=0;
			// Arithmetic detection complete
	if(flag1==1)
	{
		case1=1;
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
	//	ARITHMETIC CASE COMPLETE
	
	

	//
	return 0;
}
