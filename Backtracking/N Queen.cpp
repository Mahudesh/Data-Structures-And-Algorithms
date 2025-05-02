
// vector<vector<string>>allSolutions;
// vector<vector<int>>board;
// int n;
class Solution {
public:
 bool isSafe(int row, int col, vector<vector<int>>& board, int n)
  {
      int duprow=row;
      int dupcol=col;
      
      while(row>=0 && col>=0)
      {
          if(board[row][col]==1)
          return false;
          
          row--;
          col--;
      }
      row=duprow;
      col=dupcol;
      while(col>=0)
      {
          if(board[row][col]==1)
          return false;
          col--;
      }
      row=duprow;
      col=dupcol;
      while(row<n && col>=0)
      {
          if(board[row][col]==1)
          return false;
          
          row++;
          col--;
      }
      return true;
  }
  void solve(int cols, int n,vector<vector<int>>& board,vector<string>& temp, vector<vector<string>>& ans)
  {
      if(cols>=n)
      {
          ans.push_back(temp);
          return;
      }
      for(int i=0;i<n;i++)
      {
          if(isSafe(i,cols,board,n))
          {
              board[i][cols]=1;
            //   temp.push_back(i+1);
              temp[i][cols]='Q';
              solve(cols+1,n,board,temp,ans);
              board[i][cols]=0;
              temp[i][cols]='.';
            //   temp.pop_back();
          }
      }
  }
    vector<vector<string>> solveNQueens(int n)
     {

        vector<vector<string>>ans;
        vector<string>temp(n,string(n,'.'));
        vector<vector<int>>board(n, vector<int>(n,0));
        solve(0,n,board,temp,ans);
        return ans;
        // allSolutions.clear();
        // ::n=n;
        // if(n==2 || n==3)
        // {
        //     return {};
        // }
        // vector<string>temp(n,string(n,'.'));
        // board.assign(n, vector<int>(n,0));
        // solve(0,temp);
        // return allSolutions;
    }
};
// string temp="";r

//Place By Rows
#include<bits/stdc++.h>
using namespace std;

// Function to print the board
void print(vector<vector<int>>& board, int n)
{
    for(auto it: board)
    {
        for(auto it2:it)
            cout << it2 << " ";
        cout << endl;
    }
    cout << endl;
}

// Check if it's safe to place a queen at board[row][col]
bool isSafe(int row, int col, vector<vector<int>>& board, int n)
{
    int duprow = row;
    int dupcol = col;

    // Check same column (above)
    for(int i = 0; i < row; i++)
        if(board[i][col] == 1)
            return false;

    // Check upper-left diagonal
    int i = row, j = col;
    while(i >= 0 && j >= 0)
    {
        if(board[i][j] == 1)
            return false;
        i--; j--;
    }

    // Check upper-right diagonal
    i = row, j = col;
    while(i >= 0 && j < n)
    {
        if(board[i][j] == 1)
            return false;
        i--; j++;
    }

    return true;
}

// Backtracking function to place queens row by row
void solve(int row, int n, vector<vector<int>>& board)
{
    if(row == n)
    {
        print(board, n);
        return;
    }

    for(int col = 0; col < n; col++)
    {
        if(isSafe(row, col, board, n))
        {
            board[row][col] = 1;           // Place queen
            solve(row + 1, n, board);      // Go to next row
            board[row][col] = 0;           // Backtrack
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    solve(0, n, board);  // Start from row 0
}

