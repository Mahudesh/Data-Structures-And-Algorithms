class Solution {
public:
int helper(vector<int>& nums, int ind, int prev_ind, vector<vector<int>>& dp)
{
    if(ind==nums.size())
    return 0;
    if(dp[ind][prev_ind+1]!=-1)
    return dp[ind][prev_ind+1];
    int notTake=0+helper(nums,ind+1,prev_ind,dp);
    int take=0;
    if(prev_ind==-1 || nums[ind]>nums[prev_ind])
    {
        take=1+helper(nums,ind+1,ind,dp);
    }
    return dp[ind][prev_ind+1]=max(notTake,take);
}
    int lengthOfLIS(vector<int>& nums)
     {
        int n=nums.size();
        // vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        // return helper(nums,0,-1,dp);

        //Tabulation Approach
        //Bottom Up Approach
        vector<vector<int>>dp(n+1, vector<int>(n+1,0));

        for(int prev=0;prev<=n;prev++)
        dp[n][prev]=0;

        for(int ind=n-1;ind>=0;ind--)
        {
            for(int prev_ind = -1;prev_ind<=n-1;prev_ind++)
            {
                int notTake=0+dp[ind+1][prev_ind+1];
                int take=0;
                if(prev_ind== -1 || nums[ind]>nums[prev_ind])
                {
                    take=1+dp[ind+1][ind+1];
                }
                dp[ind][prev_ind+1]=max(notTake,take);
            }
        }
        return dp[0][0];
    }
};
