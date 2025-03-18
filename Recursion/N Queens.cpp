#include <bits/stdc++.h> 
void helper(int n, int col, vector<int>& lowerDiagonal, vector<int>& upperDiagonal, vector<int>& left, vector<vector<int>>& ans, vector<vector<int>>& board)
{
	if(col>=n)
	{
		vector<int>temp;
		for(auto it : board)
		{
			for(auto it2 : it)
			temp.push_back(it2);
		}
		ans.push_back(temp);
		return;
	}
	for(int row=0;row<n;row++)
	{
		if(left[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1+(col-row)]==0){
		board[row][col]=1;
		left[row]=1;
		lowerDiagonal[row+col]=1;
		upperDiagonal[n-1+(col-row)]=1;
		helper(n,col+1,lowerDiagonal,upperDiagonal,left,ans,board);
		board[row][col]=0;
		left[row]=0;
		lowerDiagonal[row+col]=0;
		upperDiagonal[n-1+(col-row)]=0;

		}
	}
}
vector<vector<int>> nQueens(int n)
{
	// Write your code here
	vector<vector<int>>ans;
	vector<vector<int>>board(n, vector<int>(n,0));
	vector<int>lowerDiagonal((2*n)-1,0);
	vector<int>upperDiagonal((2*n)-1,0);
	vector<int>left(n,0);
	helper(n,0,lowerDiagonal,upperDiagonal,left,ans,board);
	return ans;
	
}
