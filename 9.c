#include <stdio.h>
#include <stdlib.h>
#define LEN 64
int main(int argc, char*argv[])
{
	FILE*fp=fopen(argv[1],"r");
	char line[LEN];
	int countlines=0;
	
	while(fgets(line,LEN,fp)!=NULL)
		countlines++;
	rewind(fp);
	
	long long numbers[countlines];
	
	int k=0;
	
	while(fgets(line,LEN,fp)!=NULL)
		numbers[k++]=atoll(line);
	
	int i,j,m;
	int flag;

	for(i=25;i<countlines;i++) 
	{	
		flag=1;
		for(j=i-25;j<i-1;j++)
		{
			for(m=j+1;m<i;m++)
			{
				if(numbers[j] + numbers[m] == numbers[i])
				{
					flag=0;
					break;
				}
				if(flag==0)
					break;
			}
			if(flag==0)
				break;
		}
		if(flag)
			break;
	}
	
	printf("%lld\n",numbers[i]);
	return 0;
}
