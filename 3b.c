#include <stdio.h>
#define LINELEN 128

int runslope(int right, int down, char filename[32])
{
	char line[LINELEN];
	int path=0;
	FILE *fp;
	fp=fopen(filename,"r");
	int len;
	fgets(line,LINELEN,fp);
	for(len=0;;len++)
		if(line[len]=='\0')
			break;
	len--;
	int treecount=0;
	while(fgets(line,LINELEN,fp)!=NULL)
	{
		for(int i=1;i<down;i++)
			fgets(line,LINELEN,fp);
		path=(path+right)%len;
		if(line[path]=='#')
			treecount++;

	}
	fclose(fp);

	return treecount;
}

int main(int argc, char *argv[])
{
	long long totalcount=1;
	
	for(int i=1;i<8;i=i+2)
		totalcount = totalcount * runslope(i,1,argv[1]);
	totalcount = totalcount *  runslope(1,2,argv[1]);

	printf("%lld\n",totalcount);
	return 0;
}
