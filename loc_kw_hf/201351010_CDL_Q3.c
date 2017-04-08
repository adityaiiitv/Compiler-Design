/* Aditya Prakash 201351010 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define KEYS 32

struct keyword			// STRUCTURE TO STORE NAMES OF KEYWORDS AND OCCURANCES
{
	char name[10];
    int occur;
};

int binarysearch(char *name, struct keyword key[])		// FUNCTION TO IMPLEMENT BINARY SEARCH
{
    int l, h, m;
    l = 0;
    h = KEYS - 1;
    while (l <= h)
    {
		m = (l + h) / 2;
        if (strcmp(name, key[m].name) < 0)
        {
            h = m - 1;
        }
        else if (strcmp(name, key[m].name) > 0)
        {
            l = m + 1;
        }
        else
        {
            return m;
        }
    }
    return -1;
}

int main()				// MAIN FUNCTION
{
    int i = 0, j = 0, pos;
    char string[10000], unit[20],ch[1];
    struct keyword key[32] = {"auto", 0, "break", 0, "case", 0,"char", 0, "const", 0, "continue", 0,"default", 0, "do", 0, "double", 0,"else", 0, "enum", 0, "extern", 0,"float", 0, "for", 0, "goto", 0,"if", 0, "int", 0, "long", 0,"register", 0, "return", 0, "short", 0,"signed", 0, "sizeof", 0, "static", 0,"struct", 0, "switch", 0, "typedef", 0,"union", 0, "unsigned", 0, "void", 0,"volatile", 0, "while", 0};

	FILE *fptr;			// HANDLING THE FILE
	if ((fptr=fopen("CD_lab1.c","r"))==NULL)
	{
		printf("Error! opening file");	// IF UNABLE TO OPEN
	}
	fseek(fptr, 0, 0);					// RESET THE POINTER
	
	while ((ch[0] = fgetc(fptr)) != EOF)// MAIN LOGIC
    {   
		if (ch[0]  ==  '/')
        {
            ch[0] = fgetc(fptr);
            if (ch[0]  ==  '/')
            {
                strcat(string," ");
                do
                {
					ch[0]=fgetc(fptr);}while(ch[0]!='\n');
				}
            else if(ch[0]  ==  '*')
            {
                strcat(string," ");
                do
                {
					ch[0]=fgetc(fptr);
                    if(ch[0]=='\n')
                        strcat(string," ");
                    if(ch[0]=='*')
                        if((ch[0]=fgetc(fptr))  ==  '/')
                        {
                            strcat(string," ");
                            break;
                        }
                }while(ch[0]!='*');                
            } 
        }
        else if (ch[0]  !=  '/')
            {
               strcat(string, ch);			// CONCATENATE THE STRING IF NOT MATCHES THE CRITERIA. SAME DONE ABOVE
            }
    }
    
    for (i = 0; i < strlen(string); i++)
    {
        while (i < strlen(string) && string[i] != ' ' && isalpha(string[i]))
        {
            unit[j++] = tolower(string[i++]);
        }
        if (j != 0)
        {
            unit[j] = '\0';
            pos = binarysearch(unit, key);
            j = 0;
            if (pos != -1)
            {
               key[pos].occur++;
            }
        }
    }
    printf("\nKeywords\tOccurence\n");		// PRINTING
    for (i = 0; i < KEYS; i++)
    {
        if (key[i].occur)
        {
            printf("%s\t        %d\n", key[i].name, key[i].occur);
        }
    }
    return 0;
}
// END OF CODE
