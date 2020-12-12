#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 16
void main(int argc, char* argv[])
{
	FILE*fp=fopen(argv[1],"r");
	char line[LEN];
	
	int x,y;
	x=y=0;
		
	int d;		// direction
	int u;		// distance
	
	enum directions{E, S, W, N} 
		cd, dir;
	
	cd=E;	// current direction
	
	while(fgets(line,LEN,fp)!=NULL)
	{
		d=line[0];
		line[0]='0';
		u=atoi(line);
		
		if(d=='E') dir=E;
		if(d=='S') dir=S;
		if(d=='W') dir=W;
		if(d=='N') dir=N;
		
		if(d=='F') dir=cd;
		
		if(d=='R'||d=='L')
		{
			u=u/90;

			if(dir=='R') 
				cd=(cd+u)%4;
			else 
				cd=(cd+4-u)%4;
				
			continue;
		}
		
		switch(dir)
		{
			case N:
				y+=u;
				cd=N;
				break;
			case S:
				cd=S;
				y-=u;
				break;
			case E:
				cd=E;
				x+=u;
				break;
			case W:
				cd=W;
				x-=u;
				break;
		}
		
	}
	

	if(x<0) x*=-1;
	if(y<0) y*=-1;
	
	printf("%d\n",x+y);
	
	return;
}
