#include <bits/stdc++.h> 
bool isSafe(vector<vector<int>>& grid, int row, int col, int num)
{
    for(int i=0;i<9;i++)
    {
        if(grid[i][col]==num || grid[row][i]==num)
        return false;
    }
    int nrow=row-(row%3);
    int ncol=col-(col%3);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(grid[i+nrow][j+ncol]==num)
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>>& grid)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(grid[i][j]!=0)
            continue;
            for(int num=1;num<=9;num++)
            {
                if(isSafe(grid,i,j,num))
                {
                    grid[i][j]=num;
                    if(solve(grid))
                    return true;
                    grid[i][j]=0;
                }
            }
            return false;
        }
    }
    return true;
}
void solveSudoku(vector<vector<int>>& sudoku)
{
	// Write your code here
    // No need to print the final sudoku
    // Just fill the values in the given matrix
    solve(sudoku);
}
