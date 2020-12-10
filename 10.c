#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINELEN 8
#define MAX 1000
int main(int argc, char *argv[])
{
	FILE*fp=fopen(argv[1],"r");
	
	char line[LINELEN];
	int line_count=0;
	
	char last_line[LINELEN];
	
	// to get the line count for array
	while(fgets(line,LINELEN,fp)!=NULL)
	{
		strcpy(last_line, line);
		line_count++;
	}
	
	// in case the last line is an empty string
	if(strlen(last_line)==0)
		line_count--;
		
	rewind(fp);
	int lines[line_count];  
	int k=0;
	
	// copy file to array
	while(fgets(line,LINELEN,fp)!=NULL)
		lines[k++]=atoi(line);
	
	fclose(fp);
	
	int min=MAX;
	int minindex;
	int temp;
	
	// sorting
	for(int i=0;i<line_count-1;i++)
	{
		min=MAX;
		for(int j=i+1;j<line_count;j++)
		{
			if(lines[j]<min)
			{
				min=lines[j];
				minindex=j;
			}
		}
		if(lines[i]>lines[minindex])
		{
			temp=lines[minindex];
			lines[minindex]=lines[i];
			lines[i]=temp;
		}
	}
	
	int jolts[3]={1,1,1};
	for(int i=0;i<line_count-1;i++)
		jolts[lines[i+1]-lines[i]-1]++;
		
	printf("%d\n",jolts[0]*jolts[2]);
	return 0;
}
