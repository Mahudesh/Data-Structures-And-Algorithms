int helper(int i, int n, vector<int>&arr, int k, vector<int>& dp)
{
    if(i==n)
    return 0;

    if(dp[i]!=-1)
    return dp[i];
    int maxEle=(-1e9);
    int maxi=(-1e9);
    int len=0;
    for(int j=i;j<= min(n-1,i+k-1);j++)
    {
        len++;
        maxEle=max(maxEle,arr[j]);
        int sum=(maxEle*len)+helper(j+1,n,arr,k,dp);
        maxi=max(maxi,sum);
    }
    return dp[i]=maxi;
}
int maximumSubarray(vector<int> &arr, int k)
{
    // Write your code here.
    vector<int>dp(arr.size(),-1);
    return helper(0,arr.size(),arr,k,dp);
}
