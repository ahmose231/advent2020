#include <stdio.h>
#include <stdlib.h>
#define LEN 64
int main(int argc, char*argv[])
{
	FILE*fp=fopen(argv[1],"r");
	char line[LEN];
	int total_lines=0;
	
	while(fgets(line,LEN,fp)!=NULL)
		total_lines++;
	rewind(fp);

	
	long long numbers[total_lines];
	
	int k=0;
	
	while(fgets(line,LEN,fp)!=NULL)
		numbers[k++]=atoll(line);
	
	int i,j,m;
	int flag;

	for(i=25;i<total_lines;i++) 
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
	
	long long invalid_number=numbers[i];
	
	long long sum;
	long long min;
	long long max;
	
	for(i=0;i<total_lines;i++)
	{
		sum=0;
		for(j=i;sum<=invalid_number;j++)
		{
			sum += numbers[j];
			if(sum==invalid_number)
			{
				min=max=numbers[i];
				for(int w=i+1;w<=j;w++)
				{
					if(min>numbers[w])
						min=numbers[w];
					if(max<numbers[w])
						max=numbers[w];
				}
				printf("%lld\n",min+max);
				return 0;
			}
		}
	}
	
	return 0;
}
