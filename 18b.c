#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 1024

long long int do_final(char *line)
{
	int len=strlen(line);
	char oldline[len];
	strcpy(oldline,line);
	

	long long int sum=0;
	int op=0; 	// 1 for +, 2 for *

	int cycle=1;
	char *token;
	
	long long int a=999,b=888;
	int count=0;
	int tokenlen[99];
	char lastpart[strlen(line)];
top:
	count=0;

	cycle=1;
	op=0;
	token=strtok(line," ");
	while(token!=NULL)
	{	

		tokenlen[count++]=strlen(token);
		switch(cycle)
		{
			case 1:
				
				switch(op)
				{
					case 1:
						a=b;
						b = atoll(token);
						count=count-3;
						int leftindex=0;
						for(int i=0;i<count;i++)
							leftindex += tokenlen[i] + 1;
						int rightindex=0;
						for(int i=0;i<count+3;i++)
							rightindex += tokenlen[i] + 1;
						
						strcpy(lastpart, &oldline[rightindex-1]);
						oldline[leftindex]='\0';	

						sprintf(oldline,"%s%lld%s",oldline,a+b,lastpart);

						for(int m=0;m<strlen(oldline);m++)
						{
							if(oldline[m]=='+')
							{
								strcpy(line,oldline);
								goto top;
							}
						}

						break;
						
					case 2:
						a=b;
						b = atoll(token);
						break;
					default:
						b=atoll(token);
						break;
				}
				cycle=2;
				break;
			
			case 2:

				switch(token[0])
				{
					case '+':
						op=1;
						break;
					case '*':
						op=2;
						
						break;
				}
				cycle=1;
				break;
		}
		
		token=strtok(NULL," ");
	}

	op=1;
	cycle=1;
	strcpy(line,oldline);

	token=strtok(line," ");
	while(token!=NULL)
	{	
		switch(cycle)
		{
			case 1:
 
				switch(op)
				{
					case 1:
						sum += atoll(token);
						break;
					case 2:
						sum *= atoll(token);
						break;
				}
				cycle=2;
				break;
 
			case 2:
				switch(token[0])
				{
					case '+':
						op=1;
						break;
					case '*':
						op=2;
						break;
				}
				cycle=1;
				break;
		}
 
		token=strtok(NULL," ");
	}
	
	return sum;
}
				

long long int do_line(char *line)
{

	int len=strlen(line);
	char firsthalf[len];
	char lasthalf[len];
	char *newline=malloc(len);
	newline[0]='\0';
	int k=0;
	int flag;
	int b=0;
	int p=0;
	for(int i=0;i<len;i++)
		if(line[i]=='(')
		{
			p=1;
			b=i;
			flag=0;
			for(int j=i+1;j<len;j++)
			{
				if(line[j]=='(')
				{
					k=0;
					flag=1;
					i=j-1;
					break;
				}
				if(line[j]==')')
				{
					newline[k]='\0';	
					break;
				}
				newline[k++]=line[j];
			}
			if(!flag)
				break;
		}
	

	if(p==0)
		return do_final(line);

	len=strlen(newline);

	for(int i=0;i<b;i++)
		firsthalf[i]=line[i];
	firsthalf[b]='\0';
	
	k=0;
	

	for(int i=b+len+2;i<strlen(line);i++)
		lasthalf[k++]=line[i];
	lasthalf[k]='\0';

	long long int n=do_final(newline);
	
	sprintf(line, "%s%lld%s", firsthalf, n, lasthalf);

	return do_line(line);
}
	
	
		

void main()
{
	char line[LEN];
	long long int sum=0;
	while(fgets(line,LEN,stdin)!=NULL)
	{

		int len=strlen(line);
		
		if(len<2) continue;
		if(line[len-1]=='\n' || line[len-1]==EOF)
			line[len-1]='\0';
			
		sum += do_line(line);


	}
	
	printf("%lld\n",sum);

	return;
}
		
