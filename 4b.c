#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINELEN 128
#define STACKLEN 32

	
int main(int argc, char* argv[])
{
	FILE* fp=fopen(argv[1],"r");
	char line[LINELEN];
	int flag=0;
	char *token;
	char passport[8][STACKLEN];
	char *part1;
	char *part2;
	char eye_colors[7][4]={"amb","blu","brn","gry","grn","hzl","oth"};
	int bigcounter=0;
	int smallcounter;
	int valid;
	int invalid;
	int num;
	int in_cm;
	int totalvalid=0;
	
	while(1)
	{		
		while(1)
		{
			if(fgets(line,LINELEN,fp)==NULL)
			{
				flag=1;
				break;
			}
			
			if(line[0]=='\n')
			{
				passport[smallcounter-1][strlen(passport[smallcounter-1])-1]='\0';
				break;
			}
			
			smallcounter=0;
			
			token=strtok(line," ");
			while(token!=NULL)
			{
				strcpy(passport[smallcounter], token);
				token=strtok(NULL," ");
				smallcounter++;
			}
		}
		
		bigcounter++;
		if(smallcounter<7)
		{
			if(flag) break;
			continue;
		}
		valid=1;

		for(int i=0;i<smallcounter;i++)
		{
			part1=strtok(passport[i],":");
			part2=strtok(NULL,":");

			if(strcmp(part1,"byr")==0)
			{
				num=atoi(part2);
				if(!(num>=1920 && num<=2002))
				{
					valid=0;
					break;
				}
			}
			
			if(strcmp(part1,"iyr")==0)
			{
				num=atoi(part2);
				if(!(num>=2010 && num<=2020))
				{
					valid=0;
					break;
				}
			}				
			
			if(strcmp(part1,"eyr")==0)
			{
				num=atoi(part2);
				if(!(num>=2020 && num<=2030))
				{
					valid=0;
					break;
				}
			}	
			
			if(strcmp(part1,"hgt")==0)
			{
				if(part2[strlen(part2)-2]=='i') // "inch"
					in_cm=0;
				else
					in_cm=1;		// "cm"
					
				part2[strlen(part2)-2]='\0';
				num=atoi(part2);
				
				if(in_cm)
				{
					if(!(num>=150 && num<=193))
					{
						valid=0;
						break;
					}
				}
				else
				{
					if(!(num>=59 && num<=76))
					{
						valid=0;
						break;
					}
				}
			}
			
			if(strcmp(part1,"hcl")==0)
			{
				if(part2[0]!='#')
					{valid=0;break;}
				
				if(strlen(part2)!=7)
					{valid=0;break;}
				
				invalid=0;
				for(int i=1;i<7;i++)
				{
					if(!((part2[i]>='0' && part2[i]<='9') ||
					(part2[i]>='a' && part2[i]<='f')))
						{valid=0;invalid=1;break;}
				}
				if(invalid)
					break;
			}					
			
			if(strcmp(part1,"ecl")==0)
			{
				invalid=1;
				for(int j=0;j<7;j++)
				{
					if(strcmp(part2, eye_colors[j])==0)
					{
						invalid=0;
						break;
					}
				}
				if(invalid)
				{
					valid=0;
					break;
				}
			}
			
			if(strcmp(part1,"pid")==0)
			{
				num=strlen(part2);
				if(num!=9)
				{
					valid=0;
					break;
				}
				
				for(int j=0;j<num;j++)
					if(!(part2[j]>='0' && part2[j]<='9'))
					{
						valid=0;
						break;
					}
			}
			
			if(strcmp(part1,"cid")==0)
			{
				smallcounter--;
				if(smallcounter!=7)
					{valid=0;break;}
			}
		}
		
		
		if(valid)
			totalvalid++;

		if(flag)
			break;
	}
	
	printf("%d\n",totalvalid);
	return 0;
}
