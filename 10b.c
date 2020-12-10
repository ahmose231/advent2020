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
		lines[k++] = atoi(line);
	
	fclose(fp);
	
	int min=MAX;
	int minindex;
	int temp;
	
	// sorting
	for(int i=0; i < line_count - 1; i++)
	{
		min=MAX;
		for(int j=i+1;j<line_count;j++)
		{
			if(lines[j] < min)
			{
				min=lines[j];
				minindex=j;
			}
		}
		if(lines[i] > lines[minindex])
		{
			temp=lines[minindex];
			lines[minindex]=lines[i];
			lines[i]=temp;
		}
	}
	
	int onecount;
	long long total=1;
	int first=1;

	for(int i=0; i < line_count - 1; i++)
	{	

		onecount=0;

		if(lines[i+1] - lines[i] == 1)
		{
		        // the "first" is for the "charging outlet"
			if(first)
			{
				onecount=1;
				first=0;
			}

			for(int j=i; lines[j+1]-lines[j]==1 && j<line_count; j++)
				onecount++;
		}
		
		// three ones in a row, two combinations
		if(onecount == 2)
			total = total * 2;

		// four combinations for each 4 ones in a row
		if(onecount > 2)
			total = total * 4 * (onecount - 2);

		i += onecount;
	}
	
	printf("%lld\n",total);		
	return 0;
}
