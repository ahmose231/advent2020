#include<stdio.h>
#define LEN 16

int do_col(char line[LEN])
{
	int front,back;
	front=0;
	back=128;
	
	for(int i=0;i<7;i++)
	{
		if(line[i]=='F')
			back=((back-front)/2)+front;
		else
			front=((back-front)/2)+front;
	}
	
	return front;
}
			
int do_row(char line[LEN])
{
	int right,left;
	left=0;
	right=8;
	
	for(int i=7;i<10;i++)
	{
		if(line[i]=='L')
			right=((right-left)/2)+left;
		else
			left=((right-left)/2)+left;
	}
	
	return left;
}

int main(int argc, char * argv[])
{
	char line[LEN];
	FILE *fp;
	fp=fopen(argv[1],"r");

	int total;
	int max=0;
	while(fgets(line,LEN,fp)!=NULL)
	{
		total=(do_col(line)*8)+do_row(line);
		if(max<total)
			max=total;
	}
	
	printf("%d\n",max);
	fclose(fp);
	
	return 0;
}
