#include <stdio.h>
#define LINELEN 128
int main(int argc, char *argv[])
{
	char line[LINELEN];
	int path=0;
	FILE *fp;
	fp=fopen(argv[1],"r");
	int len;
	fgets(line,LINELEN,fp);
	for(len=0;;len++)
		if(line[len]=='\0')
			break;
	len--;
	int treecount=0;
	while(fgets(line,LINELEN,fp)!=NULL)
	{
		path=(path+3)%len;
		if(line[path]=='#')
			treecount++;
	}
	printf("%d\n",treecount);
	fclose(fp);
	return 0;
}
