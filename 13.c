// gets the wrong answer

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 1024
void main(int argc, char *argv[])
{
	FILE*fp=fopen(argv[1],"r");
	char line[LEN];
	
	int timestamp;
	
	fgets(line,LEN,fp);
	timestamp=atoi(line);
	
	fgets(line,LEN,fp);
	char *token;
	
	token=strtok(line,",");
	int bus;
	int t;
	int min=1000000;
	int answer;
	while(token!=NULL)
	{
		if(token[0]='x')
		{
			token=strtok(NULL,",");
			continue;
		}
		
		bus=atoi(token);
		
		t=(timestamp+bus)%bus;
		if(t<min)
		{
			min=t;
			answer=min*bus;
		}
		
		token=strtok(NULL,",");
	}
	
	printf("%d\n",answer);
	return;
}
		
			
