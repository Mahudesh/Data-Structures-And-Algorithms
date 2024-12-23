#include <bits/stdc++.h> 
int helper(vector<int>& arr, int ind, int target, vector<vector<int>>& dp)
{
    if(ind==0)
    {
        if(arr[ind]==0 && target==0)
        return 2;
        if(target==0 || arr[ind]==target)
        return 1;
        return 0;
    }
    if(dp[ind][target]!=-1)
    return dp[ind][target];
    int notPick=helper(arr,ind-1,target,dp);
    int pick=0;
    if(arr[ind]<=target)
    {
        pick=helper(arr,ind-1,target-arr[ind],dp);
    }
    return dp[ind][target]=pick+notPick;
}
int targetSum(int n, int target, vector<int>& arr) 
{
    // Write your code here.
    int totSum=accumulate(arr.begin(),arr.end(),0);
    if(totSum-target<0 || (totSum-target)%2!=0)
    return 0;
    // vector<vector<int>>dp(n, vector<int>(totSum+1,-1));
    // return helper(arr,n-1,(totSum-target)/2,dp);
    totSum=(totSum-target)/2;
    vector<vector<int>>dp(n, vector<int>(totSum+1,0));

    if(arr[0]==0)
    dp[0][0]=2;
    else
    dp[0][0]=1;
     if (arr[0]!=0 && arr[0]<=totSum)
    dp[0][arr[0]]=1;
    for(int ind=1;ind<n;ind++)
    {
        for(int t=0;t<=totSum;t++)
        {
            int notPick=dp[ind-1][t];
            int pick=0;
            if(arr[ind]<=t)
            pick=dp[ind-1][t-arr[ind]];
            dp[ind][t]=notPick+pick;
        }
    }
    return dp[n-1][totSum];
}
