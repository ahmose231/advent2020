#include <stdio.h>
#define INPUTCOUNT 6
#define LIST_LEN 2020
int main()
{
	int puzzle[]={8,11,0,19,1,2};
	int list[LIST_LEN];
	for(int i=0;i<INPUTCOUNT;i++)
		list[i]=puzzle[i];
	int last;
	for(int i=INPUTCOUNT;i<LIST_LEN;i++)
	{
		last=0;
		for(int j=i-2;j>=0;j--)
			if(list[i-1]==list[j])
			{
				last=j+1;
				break;
			}
		if(last)
			list[i]=i-last;
		else
			list[i]=0;
	}
	
	printf("%d\n",list[LIST_LEN-1]);
	return 0;
}

		
