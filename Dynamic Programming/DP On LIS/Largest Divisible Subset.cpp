class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        //Sort The Array And Think In Terms Of Longest Increasing Subsequence
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>hash(n);
        int maxi=1;
        int last_index=0;
        for(int i=0;i<nums.size();i++)
        {
            hash[i]=i;
           for(int prev_ind=0;prev_ind<=i-1;prev_ind++)
           {
                if(nums[i]%nums[prev_ind]==0 || nums[prev_ind]%nums[i]==0)
                {
                    if(1+dp[prev_ind]>dp[i])
                    {
                        dp[i]=1+dp[prev_ind];
                        hash[i]=prev_ind;
                    }
                }
           }
        //    int maxi=max(maxi,dp[i]);
        if(maxi<dp[i])
        {
            maxi=dp[i];
            last_index=i;
        }
        }

        //Backtrack And Find Its Array
        vector<int>ans;
        ans.push_back(nums[last_index]);
        while(hash[last_index]!=last_index)
        {
            last_index=hash[last_index];
            ans.push_back(nums[last_index]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
