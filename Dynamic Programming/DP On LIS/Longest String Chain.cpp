class Solution {
public:
// int helper(vector<int>& nums, int ind, int prev_ind, vector<vector<int>>& dp)
// {
//     if(ind==nums.size())
//     return 0;
//     if(dp[ind][prev_ind+1]!=-1)
//     return dp[ind][prev_ind+1];
//     int notTake=0+helper(nums,ind+1,prev_ind,dp);
//     int take=0;
//     if(prev_ind==-1 || nums[ind]>nums[prev_ind])
//     {
//         take=1+helper(nums,ind+1,ind,dp);
//     }
//     return dp[ind][prev_ind+1]=max(notTake,take);
// }
int lb(vector<int>&arr, int ele)
{
    int low=0;
    int high=arr.size()-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]>=ele)
        high=mid-1;
        else
        low=mid+1;
    }
    return low;
}
    int lengthOfLIS(vector<int>& nums)
     {
        int n=nums.size();
        // vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        // return helper(nums,0,-1,dp);

        //Tabulation Approach
        //Bottom Up Approach
        // vector<vector<int>>dp(n+1, vector<int>(n+1,0));

        // for(int prev=0;prev<=n;prev++)
        // dp[n][prev]=0;

        // for(int ind=n-1;ind>=0;ind--)
        // {
        //     for(int prev_ind = -1;prev_ind<=n-1;prev_ind++)
        //     {
        //         int notTake=0+dp[ind+1][prev_ind+1];
        //         int take=0;
        //         if(prev_ind== -1 || nums[ind]>nums[prev_ind])
        //         {
        //             take=1+dp[ind+1][ind+1];
        //         }
        //         dp[ind][prev_ind+1]=max(notTake,take);
        //     }
        // }
        // return dp[0][0];

        //Binary Search Method

        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(nums[i]>ans.back())
            {
                ans.push_back(nums[i]);
            }
            else
            {
                //If It Is Not In LIS Property Then Check For The Element Where It Can Be Fit Into It
                //It Can Be Done By USing The Lower Bound Concept
                int lower_bound_index=lb(ans,nums[i]);
                ans[lower_bound_index]=nums[i];
            }
        }
        return ans.size();
        
    }
};
