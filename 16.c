#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RULECOUNT 64
#define LEN 128
#define WORD 16

struct proto_rules {
    int begin;
    int end;
};


void main()
{
    char line[LEN];
    struct proto_rules rules[RULECOUNT];
    char token[WORD];
    int k=0;
    int len;
    while(1)
    {
    
        fgets(line,LEN,stdin);
        len=strlen(line);
        if(len<2) break;
        int index;
        for(int i=0;i<len;i++)
        {
            if(line[i]==':')
            {
                index=i;
                break;
            }
        }
        int m=0;
        for(int i=index+1;i<len;i++)
        {
            if(line[i]=='-')
            {
                index=i;
                break;
            }
            token[m++]=line[i];
        }
        token[m]='\0';
        rules[k].begin=atoi(token);
        
        m=0;
        for(int i=index+1;i<len;i++)
        {
            if(line[i]==' ')
            {
                index=i;
                break;
            }
            token[m++]=line[i];
        }
        token[m]='\0';
        rules[k].end=atoi(token);
        k++;
        
        m=0;
        for(int i=index+4;i<len;i++)
        {
            if(line[i]=='-')
            {
                index=i;
                break;
            }
            token[m++]=line[i];
        }
        token[m]='\0';
        rules[k].begin=atoi(token);
        
        m=0;
        for(int i=index+1;i<len;i++)
        {
            if(line[i]==' ')
            {
                index=i;
                break;
            }
            token[m++]=line[i];
        }    
        token[m]='\0';
        rules[k].end=atoi(token);
        k++;
    }
    
    for(int i=0;i<4;i++)
        fgets(line,LEN,stdin);


    int valid;
    int total=0;
    int x;
    char *token2;
    while(fgets(line,LEN,stdin)!=NULL)
    {
        
        token2=strtok(line,",");
        while(token2!=NULL)
        {
            valid=0;
            x = atoi(token2);
            for(int i=0;i<k;i++)
                if(x >= rules[i].begin && x <= rules[i].end)
                {
                    valid=1;
                    break;
                }
            if(!valid)
                total += x;
            
            token2=strtok(NULL,",");
        }
    }
    
    printf("%d\n",total);
    
    return;
}
