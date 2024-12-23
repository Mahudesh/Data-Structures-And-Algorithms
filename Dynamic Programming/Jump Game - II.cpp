class Solution {
public:
int mod=1e9+7;
int helper(vector<int>& nums, int ind, vector<int>& dp)
{
    if(ind>=nums.size()-1)
    return 0;
    if(dp[ind]!=-1)
    return dp[ind];
    int ele=nums[ind];
    long long mini=INT_MAX;
    for(int i=1;i<=ele;i++)
    {
       long long jumps = (1LL+ helper(nums,ind+i,dp))%mod;
       if(mini>jumps)
       mini=jumps;
    }
    return dp[ind]=mini;
}
    int jump(vector<int>& nums) 
    {
        int n=nums.size();
        //Memoization
        vector<int>dp(n,-1);
        return helper(nums,0,dp);

        //Tabulation Approach
        //Bottom Up Approach
        vector<int>dp(n,0);
        dp[n-1]=0;
       
        for(int i=n-2;i>=0;i--)
        {
            int ele=nums[i];
             long long mini=INT_MAX;
            for(int j=1;j<=ele;j++)
            {
                long long jumps=0;
                if(i+j >=nums.size())
                jumps=1;
                else
                 jumps=(1LL + dp[i+j])%mod;
                if(mini>jumps)
                mini=jumps;
            }
            dp[i]=mini;
        }
        return dp[0];
    }
};
