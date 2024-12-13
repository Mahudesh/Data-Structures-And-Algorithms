#include <bits/stdc++.h> 
// int a=0;
//  void subset(vector<int> &arr,int n,int k,int sum,int index)
//  {
//    //  a=0;
//      if(index==n)
//      {
//          if(sum==k)
//          {
//          a++;
//          }
//          return;
//      }
//      subset(arr,n,k,sum,index+1);
//      subset(arr,n,k,sum+arr[index],index+1);

//  }
bool subset(vector<int>arr,int ind, int target,vector<vector<int>>& dp)
{
    if(target==0)
    return true;
    if(ind==0)
    return arr[0]==target;
    if(dp[ind][target]!=-1)
    return dp[ind][target];
    // return ;
    bool notTake=subset(arr,ind-1,target,dp);
    bool Take=false;
    if(target>=arr[ind])
    {
        Take=subset(arr,ind-1,target-arr[ind],dp);
    }
    return dp[ind][target]=notTake||Take;
}
bool subsetSumToK(int n, int k, vector<int> &arr) 
{
    //Memoization

    //Changing States Will Be ind and target
    // vector<vector<int>>dp(n, vector<int>(k+1,-1));
    // return subset(arr,n-1,k,dp);

    //Tabulation Approach
    vector<vector<bool>>dp(n, vector<bool>(k+1,false));
    //Target Can Become Zero At All The Indices
    for(int i=0;i<n;i++)
    {
        dp[i][0]=true;
    }
    //If Ind==0 Then Only arr[0] Can Make The Required Target
    dp[0][arr[0]]=true;
    for(int ind=1;ind<n;ind++)
    {
        for(int target=1;target<=k;target++)
        {
            bool notTake=dp[ind-1][target];
            bool Take=false;
            if(target>=arr[ind])
            Take=dp[ind-1][target-arr[ind]];
            dp[ind][target]=notTake||Take;
        }
    }
    return dp[n-1][k];


    
    // if(a>0)
    // {
    //     a=0;
    // return true;
    // }
    // return false;
}
