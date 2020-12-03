#include <stdio.h>
#include <stdlib.h>
#define LEN 8
int main(int argc, char *argv[])
{
	FILE *fp;
	fp=fopen(argv[1],"r");
	
	char line[LEN];
	int countlines=0;
	while(fgets(line,LEN,fp)!=NULL)
		countlines++;
		
	rewind(fp);
	int lines[countlines-1];
	int k=0;
	while(fgets(line,LEN,fp)!=NULL)
		lines[k++]=atoi(line);
	
	for(int i=0;i<k;i++)
	{
		if(lines[i]<1010)
		{
			for(int j=0;j<k;j++)
			{
				if(i==j) continue;
				if(lines[j]<1010)
				{
					for(int m=0;m<k;m++)
					{
						if(m==i) continue;
						if(m==j) continue;
						
						if(lines[i]+lines[j]+lines[m]==2020)
						{
							printf("%d\n",lines[i]*lines[j]*lines[m]);
							return 0;
						}
					}
				}
			}
		}
	}
	return 0;
}
	
	
