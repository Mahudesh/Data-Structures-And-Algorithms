// // You are using GCC
// #include<bits/stdc++.h>
// using namespace std;
// int n;
// int board[10][10];
// int sol[10][10];
// bool isSafe(int x, int y)
// {
//     return x>=0 && x<n && y>=0 && y<n && board[x][y]==1;
// }
// bool solveMazeUtil(int x, int y)
// {
//     if(x==n-1 && y==n-1 && board[x][y]==1)
//     {
//         sol[x][y]=1;
//         return true;
//     }
//     if(isSafe(x,y))
//     {
//         if(sol[x][y]==1)
//         {
//             return false;
//         }
//         sol[x][y]=1;
//         if(solveMazeUtil(x+1,y))
//         return true;
//         if(solveMazeUtil(x,y+1))
//         return true;
//         sol[x][y]=0;
//         return false;
//     }
//     return false;
// }
// void solveMaze()
// {
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             sol[i][j]=0;
//         }
//     }
//     if(solveMazeUtil(0,0)==false)
//     {
//         cout<<"Solution doesn't exist";
        
//     }
//     else
//     {
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 cout<<sol[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//     }
// }
// int main()
// {
//     cin>>n;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             cin>>board[i][j];
//         }
//     }
//     solveMaze();
// }

//Print All Paths

#include<bits/stdc++.h>
using namespace std;
void printSol(vector<vector<int>>& sol, int n)
{
    for(auto it : sol)
    {
        for(auto it2 : it)
        cout<<it2<<" ";
        cout<<endl;
    }
    cout<<endl;
}
bool isSafe(int x, int y, int n, vector<vector<int>>& board)
{
    return x>=0 && y>=0 && x<n && y<=n && board[x][y]==1;
}
void solve(int x, int y, vector<vector<int>>& board, vector<vector<int>>& sol, int n)
{
    if(x==n-1 && y==n-1 && board[x][y]==1)
    {
        sol[x][y]=1;
        printSol(sol,n);
        sol[x][y]=0;
        return;
    }
    if(isSafe(x,y,n,board))
    {
        if(sol[x][y]==1)
        return;
        
        sol[x][y]=1;
        
        solve(x+1,y,board,sol,n);
        
        solve(x,y+1,board,sol,n);
        
        sol[x][y]=0;
    }

}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>board(n, vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cin>>board[i][j];
    }
    vector<vector<int>>sol(n, vector<int>(n,0));
    
    solve(0,0,board,sol,n);

}
