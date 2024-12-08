#include <bits/stdc++.h> 
int helper(vector<vector<int>>triangle, int n, int rows, int cols,vector<vector<int>>& dp)
{
	//Base Case
	//Row Gets Increasing Hence If It Attains Last Row Return What Exactly Is There
	//For Column Since Its Going Diagonal No Out Of Bound Condition Will Be Applicable
	//Since It Never Reaches The Out Of Boundary condition
	if(rows==n-1)
	return triangle[rows][cols];
	if(dp[rows][cols]!=-1)
	return dp[rows][cols];

	int downWay=triangle[rows][cols]+helper(triangle,n,rows+1,cols,dp);
	int diagonalWay=triangle[rows][cols]+helper(triangle,n,rows+1,cols+1,dp);

	return dp[rows][cols]=min(downWay,diagonalWay);
}
int minimumPathSum(vector<vector<int>>& triangle, int n)
{
	// Write your code here.
	// vector<vector<int>>dp(n, vector<int>(n,-1));
	// return helper(triangle,n,0,0,dp);

	//Tabulation Approach
	//Bottom Up Approach
	// vector<vector<int>>dp(n, vector<int>(n,0));
	// for(int i=0;i<triangle[n-1].size();i++)
	// {
	// 	dp[n-1][i]=triangle[n-1][i];
	// }
	// for(int i=n-1;i>=0;i--)
	// {
	// 	for(int j=i;j>=0;j--)
	// 	{
	// 		if(i==n-1)
	// 		break;
	// 		int downWay=triangle[i][j]+dp[i+1][j];
	// 		int diagonalWay=triangle[i][j]+dp[i+1][j+1];
	// 		dp[i][j]=min(downWay,diagonalWay);
	// 	}
	// }
	// return dp[0][0];

	//Space Optimization
	vector<int>prev(n,0);
	for(int j=0;j<triangle[n-1].size();j++)
	{
		prev[j]=triangle[n-1][j];
	}
	for(int i=n-2;i>=0;i--)
	{
		vector<int>temp(n,0);
		for(int j=i;j>=0;j--)
		{
			//Change Next Row To Take The Value From Previous
			//Change Next Diagonal To Take The Value From Previous Rows Next Column
			temp[j]=min((triangle[i][j]+prev[j]),(triangle[i][j]+prev[j+1]));
		}
		prev=temp;
	}
	return prev[0];
}
