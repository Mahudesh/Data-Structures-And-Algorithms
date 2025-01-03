#include <bits/stdc++.h> 
int helper(int i, int j, vector<int>& cuts, vector<vector<int>>& dp)
{
    if(i>j)
    return 0;

    if(dp[i][j]!=-1)
    return dp[i][j];
    int mini=1e9;
    for(int k=i;k<=j;k++)
    {
        int cost=cuts[j+1]-cuts[i-1] + helper(i,k-1,cuts,dp) + helper(k+1,j,cuts,dp);
        mini=min(mini,cost);
    }
    return dp[i][j]=mini;
}
int cost(int n, int c, vector<int> &cuts)
{
    // Write your code here.
    sort(cuts.begin(),cuts.end());
    cuts.insert(cuts.begin(),0);
    cuts.push_back(n);

    // vector<vector<int>>dp(cuts.size(), vector<int>(cuts.size(),-1));
    // return helper(1,cuts.size()-2,cuts,dp);

    //Tabulation Approach 
    //Bottom Up Approach
    vector<vector<int>>dp(cuts.size(), vector<int>(cuts.size(),0));

    for(int i=cuts.size()-2;i>=1;i--)
    {
        for(int j=i;j<=cuts.size()-2;j++)
        {
            int mini=1e9;
            for(int k=i;k<=j;k++)
            {
                int cost=cuts[j+1]-cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                mini=min(mini,cost);
            }
            dp[i][j]=mini;
        }
    }
    return dp[1][cuts.size()-2];
}
