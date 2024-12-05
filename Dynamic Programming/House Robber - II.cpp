class Solution {
public:
int helper(int ind, vector<int>&nums,vector<int>&dp)
{
    if(ind==0)
    return nums[0];
    if(ind<1)
    return 0;
    if(dp[ind]!=-1)
    return dp[ind];
    int pick=nums[ind]+helper(ind-2,nums,dp);
    int leftOut=0+helper(ind-1,nums,dp);
    return dp[ind]=max(pick,leftOut);
}
    int rob(vector<int>& nums) 
    {
        //Make An Array With Removing First House And Considering Last House
        //Make An Array With Removing Last House And Considering First House
        if(nums.size()==1)
        return nums[0];
        int backup=nums[0];
        nums.erase(nums.begin());
        vector<int>dp(nums.size(),-1);
        int leave1stHouse= helper(nums.size()-1,nums,dp);
        nums.insert(nums.begin(),backup);
        nums.pop_back();
        fill(dp.begin(),dp.end(),-1);
        int leave2ndHouse=helper(nums.size()-1,nums,dp);
        //Answer Must Be Maximum Of Leaving1stHouse Or Leaving2ndHouse
        return max(leave1stHouse,leave2ndHouse);
    }
};
