#include <bits/stdc++.h> 
int helper(int ind,vector<int>&arr,vector<int>&dp)
{
    if(ind==0)
    return 0;

    if(dp[ind]!=-1)
    return dp[ind];

    int left=helper(ind-1,arr,dp)+abs((arr[ind]-arr[ind-1]));
    int right=INT_MAX;
    if(ind>1)
     right=helper(ind-2,arr,dp)+abs((arr[ind]-arr[ind-2]));

    return dp[ind]=min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    // vector<int>dp(n,-1);
    // return helper(heights.size()-1,heights,dp);

    //Space optimization

    // vector<int>dp(n,0);
    // dp[0]=0;
   int prev=0;
   int secPrev=0;
    int ans=0;
    for(int i=1;i<n;i++)
    {
        int jumpOne=prev+abs(heights[i]-heights[i-1]);
        int jumpTwo=INT_MAX;
        if(i>1)
         jumpTwo=secPrev+abs(heights[i]-heights[i-2]);
         ans=min(jumpOne,jumpTwo);
         secPrev=prev;
         prev=ans;
    }
    return prev;
   
    //Tabulation

    // vector<int>dp(n,0);
    // dp[0]=0;
    // int ans=0;
    // for(int i=1;i<n;i++)
    // {
    //     int jumpOne=dp[i-1]+abs(heights[i]-heights[i-1]);
    //     int jumpTwo=INT_MAX;
    //     if(i>1)
    //      jumpTwo=dp[i-2]+abs(heights[i]-heights[i-2]);
    //     dp[i]=min(jumpOne,jumpTwo);
    // }
    // return dp[n-1];
   

}
