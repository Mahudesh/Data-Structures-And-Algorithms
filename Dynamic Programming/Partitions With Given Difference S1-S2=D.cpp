#include <bits/stdc++.h> 
int mod=1e9+7;
int helper(int n, int d, vector<int>& arr,int ind, int target, vector<vector<int>>& dp)
{
    if(ind==0)
    {
        if(arr[0]==0 && target==0)
        return 2;

        if(target==0 || arr[0]==target)
        return 1;

        return 0;
    }
    if(dp[ind][target]!=-1)
    return dp[ind][target];
    int notPick=helper(n,d,arr,ind-1, target,dp);
    int pick=0;
    if(arr[ind]<=target)
    {
        pick=helper(n,d,arr,ind-1,target-arr[ind],dp);
    }
    return dp[ind][target]=(notPick+pick)%mod;
}
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int sum=accumulate(arr.begin(),arr.end(),0);
    int target=(sum-d)/2;
    if(sum-d<0)
    return 0;
    if((sum-d)%2!=0)
    return 0;
    // vector<vector<int>>dp(n, vector<int>(target+1,-1));
    // return helper(n,d,arr,n-1,target,dp);

    //Tabulation Approach

    vector<vector<int>>dp(n, vector<int>(target+1,0));

    if(arr[0]==0)
    {
        dp[0][0]=2;
    }
    else
    {
        dp[0][0]=1;
    if( arr[0]<=target)
    {
        dp[0][arr[0]]=1;
    }
    }

    for(int ind=1;ind<n;ind++)
    {
        //Here You should Run From Target 0
        //Because In Recursion We Have Written Down Only For The Base Case ind=0
        //We Does Not Write For Base Case When Target Becomes 0 At All Index Positions
        //We Did The Base Case Of Target Only For ind==0 && Target==0
        //But The Target Can Appear 0 In All Indices Of The Array
        for(int t=0;t<=target;t++)
        {
            int notPick=dp[ind-1][t];
            int pick=0;
            if(arr[ind]<=t)
            {
                pick=dp[ind-1][t-arr[ind]];
            }
            dp[ind][t]=(pick+notPick)%mod;
        }
    }
    return dp[n-1][target];
}


