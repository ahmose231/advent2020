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
	int seats[128][8];
	for(int i=0;i<128;i++)
		for(int k=0;k<8;k++)
			seats[i][k]=0;

	char line[LEN];
	FILE *fp;
	fp=fopen(argv[1],"r");

	while(fgets(line,LEN,fp)!=NULL)
		seats[do_col(line)][do_row(line)]=1;
	
	int flag=0;
	for(int i=0;i<128;i++)
		for(int k=0;k<8;k++)
		{
			if(seats[i][k]==0 && flag)
			{
				printf("%d\n",(i*8)+k);
				fclose(fp);
				return 0;
			}
			if(seats[i][k])
				flag=1;
		}
	
	return 0;
}
