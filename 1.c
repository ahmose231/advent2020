#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	FILE *fp;
	fp=fopen(argv[1],"r");
	
	char line[5];
	int countlines=0;
	while(fgets(line,5,fp)!=NULL)
		countlines++;
		
	rewind(fp);
	int lines[countlines];
	int k=0;
	while(fgets(line,5,fp)!=NULL)
		lines[k++]=atoi(line);
	
	for(int i=0;i<k;i++)
	{
		if(lines[i]<1011)
		{
			for(int j=0;j<k;j++)
			{
				if(i==j) continue;
				if(lines[i]+lines[j]==2020)
				{
					printf("%d\n",lines[i]*lines[j]);
					return 0;
				}
			}
		}
	}
	
	return 0;
}
	
	
