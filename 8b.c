#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 16

int run_program(char instructions[][LEN], int total_lines);
int accumulator;
int current_line;

int main(int argc, char* argv[])
{
	FILE*fp=fopen(argv[1],"r");
    if(fp==NULL)
    {
        printf("error: cant open file\n");
        exit(0);
    }
    
	int total_lines=0;
	char line[LEN];
	
	while(fgets(line,LEN,fp)!=NULL)
		total_lines++;
	rewind(fp);

	int lines[total_lines];

	for(int i=0;i<total_lines;i++)
		lines[i]=0;
    
    char instructions[total_lines][LEN];

    int k=0;
	while(fgets(line,LEN,fp)!=NULL)
	{
	   int len=strlen(line);
	   if(len<2) continue;
	   if(line[len-1]=='\n'||line[len-1]==EOF)
	       line[len-1]='\0';
	
	   strcpy(instructions[k], line);
	   k++;
	}
	fclose(fp);

	char *token;
	int current_line=0;
	int accumulator=0;
	int parameter;
	
	int noplines[total_lines];	
	int jmplines[total_lines];
	
	for(int i=0;i<total_lines;i++)
	{
	   if(instructions[i][0]=='n')
	       noplines[i]=1;
	   else
	       noplines[i]=0;
	       
	   if(instructions[i][0]=='j')
	       jmplines[i]=1;
	   else
	       jmplines[i]=0;
	}
	
	char instructions2[total_lines][LEN];
	
	for(int i=0;i<total_lines;i++)
	   if(noplines[i])
	   {
	       noplines[i]=0;
	       for(int j=0;j<total_lines;j++)
	           strcpy(instructions2[j], instructions[j]);
	        
	        instructions2[i][0]='j';
	        instructions2[i][1]='m';
	        
	        if(run_program(instructions2, total_lines) == total_lines)
	        {
	           printf("%s %d\n",instructions[i], accumulator);
	           exit(0);
	        }
	    }
	    
	for(int i=0;i<total_lines;i++)
	   if(jmplines[i])
	   {
	       jmplines[i]=0;
	       for(int j=0;j<total_lines;j++)
	           strcpy(instructions2[j], instructions[j]);
	        
	        instructions2[i][0]='n';
	        instructions2[i][1]='o';
	        
	        if(run_program(instructions2, total_lines) == total_lines)
	        {
	           printf("%s %d\n",instructions[i], accumulator);
	           exit(0);
	        }
	    }
	           
	

	
	
	return 0;
}
			
			

int run_program(char instructions[][LEN], int total_lines)
{
	int lines[total_lines];

	for(int i=0;i<total_lines;i++)
		lines[i]=0;
		
    char line[LEN];
    char *token;
    current_line=0;
    accumulator=0;
	int parameter;

    int flag=1;
	while(current_line>=0 && current_line<total_lines)
	{
		lines[current_line]++;

		if(lines[current_line]>1)
		{
		  flag=0;
	       break;
		}
		
		strcpy(line, instructions[current_line]);
		
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
			
			current_line += parameter;
			continue;
			
		}
	}
	if(flag) printf("acc = %d\n",accumulator);
	return current_line;
}
