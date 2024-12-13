class Solution {
public:
bool helper(vector<int> nums,int ind, int goal,vector<vector<int>>& dp)
{
    if(goal==0)
    return true;
    if(ind==0)
    {
        return nums[0]==goal;
    }
    if(dp[ind][goal]!=-1)
    return dp[ind][goal];
    bool notTake=helper(nums,ind-1,goal,dp);
    bool Take=false;
    if(goal>=nums[ind])
    {
        Take=helper(nums,ind-1,goal-nums[ind],dp);
    }
    return dp[ind][goal]=notTake||Take;

}
    bool canPartition(vector<int>& nums) 
    {

        //Logic : If There Is An Array With Sum S
        //Then If I Found An Array Of Subset With Sum As Sum/2
        //Then For Sure The Remaining Array Subset Will Contain The Another Equal Half Of The Sum/2
        int sum=accumulate(nums.begin(),nums.end(),0);
        //If Sum%2 Is Odd Then I Cannot Split Equal S1 And S2 In Entire Sum Of The Array S
        if(sum%2!=0)
        return false;
        // int n=nums.size();
        // int target=(sum/2);
        // vector<vector<int>>dp(n, vector<int>(target+1,-1));
        // return helper(nums,nums.size()-1,sum/2,dp);

        //Tabulation Approach
        int n=nums.size();
        int target=(sum/2);
        vector<vector<bool>>dp(n, vector<bool>(target+1,false));
        for(int ind=0;ind<n;ind++)
        {
            dp[ind][0]=true;
        }
        if(nums[0]<=target)
        dp[0][nums[0]]=true;
        for(int ind=1;ind<n;ind++)
        {
            for(int t=1;t<=target;t++)
            {
                bool notTake=dp[ind-1][t];
                bool take=false;
                if(nums[ind]<=t)
                {
                    take=dp[ind-1][t-nums[ind]];
                }
                dp[ind][t]=take||notTake;
            }
        }
        return dp[n-1][target];
    }
};
