#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 16
int main(int argc, char* argv[])
{
	FILE*fp=fopen(argv[1],"r");

	int total_lines=0;
	char line[LEN];
	
	while(fgets(line,LEN,fp)!=NULL)
		total_lines++;
	rewind(fp);

	int lines[total_lines];

	for(int i=0;i<total_lines;i++)
		lines[i]=0;

	char *token;
	int current_line=0;
	int accumulator=0;
	int parameter;
	
	while(fgets(line,LEN,fp)!=NULL)
	{
		lines[current_line]++;

		if(lines[current_line]>1)
			break;
		
		token=strtok(line," ");

		if(token[0]=='n')
		{
			current_line++;
			continue;
		}
		
		if(token[0]=='a')
		{
			token=strtok(NULL," ");
			accumulator += atoi(token);
			
			current_line++;
			continue;
		}
		
		if(token[0]=='j')
		{
			token=strtok(NULL," ");
			parameter=atoi(token);
			
			if(parameter<0)
			{
				rewind(fp);
				for(int i=0; i < current_line + parameter; i++)
					fgets(line,LEN,fp);
				
			} else {
				for(int i=0; i < parameter-1; i++)
					fgets(line,LEN,fp);
				}
			
			current_line += parameter;
			continue;
			
		}
	}
	
	printf("%d\n",accumulator);
	
	return 0;
}
			
			
