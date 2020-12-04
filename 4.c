#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	fp=fopen(argv[1],"r");
	
	int c;
	int markcount=0;
	int valid=0;
	
	c=fgetc(fp);
	while(1)
	{	
		if(c!='c')
			markcount++;
			
		while(1)
		{
			c=fgetc(fp);
			if(c==' ')
			{
				c=fgetc(fp);
				break;
			}
			
			if(c==EOF)
			{	
				if(markcount==7)
					valid++;
					
				fclose(fp);
				printf("%d\n",valid);

				return 0;
			}
			
			if(c=='\n')
			{
				c=fgetc(fp);
				
				if(c==EOF)
				{		
					if(markcount==7)
						valid++;
					fclose(fp);
					printf("%d\n",valid);

					return 0;
				}
				
				if(c=='\n')
				{
					if(markcount==7)
						valid++;

					markcount=0;

					c=fgetc(fp);
				}
				
				break;
			}


			
		}
	}
	
	return 0;				

}
