#include<bits/stdc++.h>
using namespace std;
int fib(int n,vector<int>&dp)
{
    if(n<=1)
    return n;
    if(dp[n]!=-1)
    return dp[n];
    return dp[n]=fib(n-1,dp)+fib(n-2,dp);
}
int main()
{
    int n=4;
    vector<int>dp(n+1,-1);
    cout<<fib(n,dp);
    int n=4;
    int prev=1;
    int secPrev=0;
    int ans=0;
  for(int i=2;i<n;i++)
    {
        ans=prev+secPrev;
        secPrev=prev;
        prev=ans;
    }
    cout<<ans;
}
