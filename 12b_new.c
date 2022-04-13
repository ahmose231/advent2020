#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 16

int main()
{
    char line[LEN];
    int wx=10, wy=1;
    int x=0, y=0;
    int n;
    char d;
    int t;
    while(fgets(line,LEN,stdin)!=NULL)
    {
        int len=strlen(line);
        if(len<2) continue;
        if(line[len-1]=='\n'||line[len-1]==EOF)
            line[len-1]='\0';

        d=line[0];
        line[0]='0';
        n=atoi(line);

        switch(d)
        {
            case 'N':wy+=n;break;
            case 'W':wx-=n;break;
            case 'S':wy-=n;break;
            case 'E':wx+=n;break;
            
            case 'R':
                switch(n)
                {
                    case 90:
                        wx*=-1;
                        
                        t=wx;
                        wx=wy;
                        wy=t;
                        
                        break;
                    
                    case 180:
                        wx*=-1;
                        wy*=-1;
                        
                        break;
                        
                    case 270:
                        wy*=-1;
                        
                        t=wx;
                        wx=wy;
                        wy=t;                       
                            
                        break;
                }
                
                break;
            
            case 'L':
                switch(n)
                {
                    case 90:
                        wy*=-1;
                        
                        t=wx;
                        wx=wy;
                        wy=t;
                        
                        break;
                    
                    case 180:
                        wx*=-1;
                        wy*=-1;
                        
                        break;
                        
                    case 270:
                        wx*=-1;
                        
                        t=wx;
                        wx=wy;
                        wy=t;                       
                            
                        break;
                }
                
                break;

            case 'F':
                x += wx * n;
                y += wy * n;
                
                break;
        }
    }
    
    printf("%d\n",abs(x)+abs(y));
    
    return 0;
}
                    
                
