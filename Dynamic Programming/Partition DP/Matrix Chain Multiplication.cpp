#include <bits/stdc++.h> 

int helper(int i, int j, vector<int>& arr, vector<vector<int>>& dp)
{
    if(i==j)
    return 0;

    int mini=1e9;

    if(dp[i][j]!=-1)
    return dp[i][j];

    for(int k=i;k<=j-1;k++)
    {
        int operations=arr[i-1] * arr[k] * arr[j] + 
                        helper(i,k,arr,dp) + helper(k+1,j,arr,dp);

        mini=min(mini,operations);
    }
    return dp[i][j]=mini;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    // vector<vector<int>>dp(N, vector<int>(N,-1));
    // return helper(1,N-1,arr,dp);
    vector<vector<int>>dp(N, vector<int>(N,0));

    //Tabulation Approach
    //Bottom Up Approach

    for(int i=1;i<N;i++)
    {
        dp[i][i]=0;
    }

    for(int i=N-1;i>=1;i--)
    {
        //Run j Loop Always From i+1
        //Since In Recursion Always j Is Greater Than i
        //It Means That Some Part Of Array Between i And j As Like As Two Pointers
        for(int j=i+1;j<N;j++)
        {
            int mini=1e9;
            for(int k=i;k<=j-1;k++)
            {
                int operations=arr[i-1] * arr[k] * arr[j] + 
                        dp[i][k] + dp[k+1][j];

                 mini=min(mini,operations);
            }
                 dp[i][j]=mini;
        }
    }
    return dp[1][N-1];
}
