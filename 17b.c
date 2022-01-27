#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INPUT 8
#define SIZE 30
#define LEN 16
#define ITERATION 6

void process(int, int, int, int); 


int grid[SIZE][SIZE][SIZE][SIZE]; 
int grid2[SIZE][SIZE][SIZE][SIZE]; 

void main()
{

    char line[LEN]; 
    int x = SIZE/2 - INPUT/2; 
    int y = SIZE/2 - INPUT/2; 
    int z = SIZE/2 - INPUT/2; 
    int w = SIZE/2 - INPUT/2; 

    for(int i = 0; i<SIZE; i++)
        for(int j = 0; j<SIZE; j++)
            for(int m = 0; m<SIZE; m++)
                for(int n = 0; n<SIZE; n++)
                    grid[i][j][m][n]  =  grid2[i][j][m][n]  =  0; 
    int k = 0; 
    while(fgets(line, LEN, stdin)!= NULL)
    {
        if(strlen(line)<2) continue; 
        for(int i = 0; i<INPUT; i++)
            if(line[i] == '#')
                grid[x + k][y + i][z][w]  =  1; 
        k++; 
    }
    
    int iterate = ITERATION; 
    while(iterate --> 0)
    {
        for(int i = 1; i<SIZE-1; i++)
            for(int j = 1; j<SIZE-1; j++)
                for(int m = 1; m<SIZE-1; m++)
                    for(int n = 1; n<SIZE-1; n++)
                        process(i, j, m, n); 
   

        for(int i = 0; i<SIZE; i++)
            for(int j = 0; j<SIZE; j++)
                for(int m = 0; m<SIZE; m++)
                    for(int n = 0; n<SIZE; n++)
                        grid[i][j][m][n] = grid2[i][j][m][n]; 
    }   
    
    int count = 0; 
    for(int i = 0; i<SIZE; i++)
        for(int j = 0; j<SIZE; j++)
            for(int m = 0; m<SIZE; m++)
                for(int n = 0; n<SIZE; n++)
                    if(grid[i][j][m][n])
                        count++; 
    printf("%d\n", count); 
    return; 
    
}




void process(int x, int y, int z, int w)
{
    int count = 0; 

    for(int i = x-1; i<x+2; i++)
        for(int j = y-1; j<y+2; j++)
            for(int m = z-1; m<z+2; m++)
                for(int n = w-1; n<w+2; n++)
                    if(grid[i][j][m][n])
                        count++; 
    
    if(grid[x][y][z][w])
    {
        if(count == 3 || count == 4)
            grid2[x][y][z][w] = 1; 
        else
            grid2[x][y][z][w] = 0; 
    }
    else
    {   
        if(count == 3)
            grid2[x][y][z][w] = 1; 
        else
            grid2[x][y][z][w] = 0; 
    }
    
    return; 
}
            


