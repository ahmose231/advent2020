#include <stdio.h>
#include <string.h>

#define LEN 32

int main(int argc, char *argv[])
{
	char line[LEN];
	FILE *fp=fopen(argv[1],"r");
	
	int alphabet[26];
	int flag=0;
	int line_len;
	int sum;
	int bigsum=0;
	
	while(1)
	{
		for(int i=0;i<26;i++)
			alphabet[i]=0;
		
		while(1)
		{
			if(fgets(line,LEN,fp)==NULL)
			{
				flag=1;
				break;
			}
			
			if(line[0]=='\n')
				break;

			line_len=strlen(line);			
			for(int i=0;i<line_len;i++)
				alphabet[line[i]-'a']++;
			
		}
		
		sum=0;
		
		for(int i=0;i<26;i++)
			if(alphabet[i])
				sum++;
		
		bigsum += sum;
		
		if(flag)
			break;
	}
	
	printf("%d\n",bigsum);
	
	return 0;
}
