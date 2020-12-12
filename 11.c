#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 256

void do_round(char **map, int row_count, int col_count)
{
	char new_map[row_count][col_count];
	
	for(int i=0;i<row_count;i++)
		for(int j=0;j<col_count;j++)
			new_map[i][j]='.';
			
	int occupied_count;

	occupied_count=0;	
	for(int i=0;i<row_count;i++)
		for(int j=0;j<col_count;j++)
		{
			if(i>=1 && i<row_count-1 && j>=1 && j<col_count-1)
				for(int a=i-1;a<i+2;a++)
					for(int b=j-1;b<j+2;b++)
						if(a!=i && b!=j)
							if(map[a][b]=='#')
								occupied_count++;
			
			switch(map[i][j])
			{
				case 'L':
					if(occupied_count==0)
						new_map[i][j]='#';
					break;
				case '#':
					if(occupied_count>=4)
						new_map[i][j]='L';
					break;
			}
		}
		
	occupied_count=0;
	for(int i=1;i<col_count-2;i++)
	{
		for(int j=i-1;j<i+2;j++)
			if(map[1][j]=='#')
				occupied_count++;

		if(map[0][i-1]=='#')
			occupied_count++;

		if(map[0][i+1]=='#')
			occupied_count++;

		switch(map[0][i])
		{
			case 'L':
				if(occupied_count==0)
					new_map[0][i]='#';
				break;
			case '#':
				if(occupied_count>=4)
					new_map[0][i]='L';
				break;
		}
	}
	
	occupied_count=0;
	for(int i=1;i<col_count-2;i++)
	{
		for(int j=i-1;j<i+2;j++)
			if(map[row_count-1][j]=='#')
				occupied_count++;
		
		if(map[row_count-1][i-1]=='#')
			occupied_count++;
		
		if(map[row_count-1][i+1]=='#')
			occupied_count++;

		switch(map[row_count-1][i])
		{
			case 'L':
				if(occupied_count==0)
					new_map[row_count-1][i]='#';
				break;
			case '#':
				if(occupied_count>=4)
					new_map[row_count-1][i]='L';
				break;
		}
	}

	occupied_count=0;
	for(int i=1;i<row_count-2;i++)
	{
		for(int j=i-1;j<i+2;j++)
			if(map[j][0]=='#')
				occupied_count++;

		if(map[i-1][0]=='#')
			occupied_count++;

		if(map[i+1][0]=='#')
			occupied_count++;				
		
		switch(map[i][0])
		{
			case 'L':
				if(occupied_count==0)
					new_map[i][0]='#';
				break;
			case '#':
				if(occupied_count>=4)
					new_map[i][0]='L';
				break;
		}
	}
	
	occupied_count=0;
	for(int i=1;i<row_count-2;i++)
	{
		for(int j=i-1;j<i+2;j++)
			if(map[j][col_count-1]=='#')
				occupied_count++;
				
		if(map[i-1][row_count-1]=='#')
			occupied_count++;

		if(map[i+1][row_count-1]=='#')
			occupied_count++;

		switch(map[i][col_count-1])
		{
			case 'L':
				if(occupied_count==0)
					new_map[i][col_count-1]='#';
				break;
			case '#':
				if(occupied_count>=4)
					new_map[i][col_count-1]='L';
				break;
		}
	}
	
	occupied_count=0;
	if(map[0][1]=='#')
		occupied_count++;
	if(map[1][1]=='#')
		occupied_count++;
	if(map[1][0]=='#')
		occupied_count++;
	switch(map[0][0])
	{
		case 'L':
			if(occupied_count==0)
				new_map[0][0]='#';
			break;
		case '#':
			if(occupied_count>=4)
				new_map[0][0]='L';
			break;
	}
	
	occupied_count=0;
	if(map[0][col_count-2]=='#')
		occupied_count++;
	if(map[1][col_count-2]=='#')
		occupied_count++;
	if(map[1][col_count-1]=='#')
		occupied_count++;
	switch(map[0][col_count-1])
	{
		case 'L':
			if(occupied_count==0)
				new_map[0][col_count-1]='#';
			break;
		case '#':
			if(occupied_count>=4)
				new_map[0][col_count-1]='L';
			break;
	}	

	occupied_count=0;
	if(map[row_count-1][1]=='#')
		occupied_count++;
	if(map[row_count-2][1]=='#')
		occupied_count++;
	if(map[row_count-2][0]=='#')
		occupied_count++;
	switch(map[row_count-1][0])
	{
		case 'L':
			if(occupied_count==0)
				new_map[row_count-1][0]='#';
			break;
		case '#':
			if(occupied_count>=4)
				new_map[row_count-1][0]='L';
			break;
	}		

	occupied_count=0;
	if(map[row_count-1][col_count-2]=='#')
		occupied_count++;
	if(map[row_count-2][col_count-2]=='#')
		occupied_count++;
	if(map[row_count-2][col_count-1]=='#')
		occupied_count++;
	switch(map[row_count-1][col_count-1])
	{
		case 'L':
			if(occupied_count==0)
				new_map[row_count-1][col_count-1]='#';
			break;
		case '#':
			if(occupied_count>=4)
				new_map[row_count-1][col_count-1]='L';
			break;
	}
	
	for(int i=0;i<row_count;i++)
		for(int j=0;j<col_count;j++)
			map[i][j]=new_map[i][j];
	
	return;
}

void main(int argc, char* argv[])
{
	FILE*fp=fopen(argv[1],"r");
	
	char line[LEN];
	
	int col_count;
	int row_count;
	
	row_count=0;
	
	while(fgets(line,LEN,fp)!=NULL)
		if(strlen(line)!=0)
			row_count++;

	rewind(fp);
	fgets(line,LEN,fp);
	col_count=strlen(line)-1;

	char **map;
	char **last_map;
	
	for(int i=0;i<row_count;i++)
		*map=malloc(col_count);
	
	for(int i=0;i<row_count;i++)
		*last_map=malloc(col_count);
		
	rewind(fp);
	for(int i=0;i<row_count;i++)
	{
		fgets(line,LEN,fp);
		strncpy(map[i],line,col_count);
	}
	fclose(fp);
	
	int flag;
	int occupied_count=0;
	

	while(1)
	{
		for(int i=0;i<row_count;i++)
			strcpy(last_map[i],map[i]);
		

		do_round(map, row_count, col_count);
		
		flag=1;
		for(int i=0;i<row_count;i++)
			if(strcmp(last_map[i],map[i])!=0)
			{
				flag=0;
				
				for(int a=0;a<row_count;a++)
					for(int b=0;b<col_count;b++)
						if(map[a][b]=='#')
							occupied_count++;
							
				break;	
			}
		
		if(flag)
			break;
	}
	
	printf("%d\n",occupied_count);
		
	return;
}
	
