#include <stdio.h>

#define LINELEN 64

int main(int argc, char* argv[])
{
	FILE *fp;
	fp=fopen(argv[1],"r");
	
	char line[LINELEN];
	int a,b;
	int key;
	char password[LINELEN];
	int k;
	int m;
	int count;
	int largercount=0;
	while(fgets(line,LINELEN,fp)!=NULL)
	{
		k=0;
		
		a=0;
		while(line[k]!='-')
		{
			a=(a*10)+(line[k]-'0');
			k++;
		}
		
		k++;  //space
		b=0;
		while(line[k]!=' ')
		{
			b=(b*10)+(line[k]-'0');
			k++;
		}
		
		k++;  // space
		key=line[k];
		k++;  // semicolon
		k++;  // space
		m=0;
		while(line[k]!='\n' && line[k]!=EOF)
		{
			password[m]=line[k];
			m++;
			k++;
		}
		
		count=0;
		for(int i=0;i<m;i++)
			if(password[i]==key)
				count++;
		
		if(count>=a && count<=b)
			largercount++;

	}
	fclose(fp);
	printf("%d\n",largercount);
	return 0;
}
		
		
