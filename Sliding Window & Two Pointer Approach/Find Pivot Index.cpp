class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        // vector<int>prefixSum(nums.size(),0);
        // vector<int>suffixSum(nums.size(),0);
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(i==0)
        //     continue;
        //     prefixSum[i]=prefixSum[i-1]+nums[i-1];
        //     suffixSum[nums.size()-1-i]=suffixSum[nums.size()-i]+nums[nums.size()-i];
        // }
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(prefixSum[i]==suffixSum[i])
        //     return i;
        //     // cout<<suffixSum[i]<<" ";
        // }
        // return -1;

        //Approach 2:
        //Using Only Prefix Sum
        vector<int>prefixSum(nums.size());
        prefixSum[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }

        if(0== (prefixSum[nums.size()-1] - prefixSum[0]))
        return 0;
        // if(prefixSum[nums.size()-2]==0)
        // return nums.size()-1;
        for(int i=1;i<nums.size();i++)
        {
            int leftSum=prefixSum[i-1];
            int rightSum=prefixSum[nums.size()-1]-prefixSum[i];
            if(leftSum==rightSum)
            return i;
        }
        return -1;


    }
};
