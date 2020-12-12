// gives wrong answer

#include <stdio.h>
#include <stdlib.h>
#define LEN 16
void main(int argc, char* argv[])
{
	FILE*fp=fopen(argv[1],"r");
	char line[LEN];
	
	int x,y;
	x=y=0;
		
	int wx,wy;  	// waypoint
	wx=10;
	wy=1;
		
	int d;		// direction
	int u;		// distance

	int temp;
	
	while(fgets(line,LEN,fp)!=NULL)
	{
		d=line[0];
		
		line[0]='0';
		u=atoi(line);
		
		if(d=='E'||d=='W'||d=='N'||d=='S')
		{
			switch(d)
			{
				case 'E':
					wx+=u;
					break;
				case 'W':
					wx-=u;
					break;
				case 'N':
					wy+=u;
					break;
				case 'S':
					wy-=u;
					break;
			}
			continue;
		}

		if(d=='F')
		{
			x+=wx*u;
			y+=wy*u;
	
			continue;
		}
		

		if(u==180)
		{
			wx*=(-1);
			wy*=(-1);
			continue;
		}
		
		temp=wx;
		
		if(u==270)
		{
			if(d=='R')
				d='L';
			else
				d='R';
		}

		if(d=='R')
		{
			if(wx>0&&wy>0)
			{wx=wy;wy=temp*(-1);continue;}
			if(wx>0&&wy<0)
			{wx=wy*(-1);wy=temp;continue;}
			if(wx<0&&wy<0)
			{wx=wy;wy=temp*(-1);continue;}
			if(wx<0&&wy>0)
			{wx=wy*(-1);wy=temp;continue;}
		}
		
		if(wx>0&&wy>0)
		{wx=wy*(-1);wy=temp;continue;}
		if(wx>0&&wy<0)
		{wx=wy;wy=temp*(-1);continue;}
		if(wx<0&&wy<0)
		{wx=wy*(-1);wy=temp;continue;}
		if(wx<0&&wy>0)
		{wx=wy;wy=temp*(-1);continue;}
		
	}

	printf("%d\n",abs(x)+abs(y));
	
	return;
}
