class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) 
    {
        int l=0;
        int r=0;
        long long sum=0;
        int du=1;
        long long maxSum=0;
        unordered_map<long long,long long>Map;
        while(r<nums.size())
        {
            sum=sum+nums[r];
            Map[nums[r]]++;
            if(Map[nums[r]]>1)
            du++;
            while(du>1)
            {
                if(Map[nums[l]]>1)
                du--;
                sum=sum-nums[l];
                Map[nums[l]]--;
                l++;
                if(r==nums.size()-1)
                return maxSum;
                r++;
                if(Map[nums[r]]>1)
                du++;
                sum=sum+nums[r];
                Map[nums[r]]++;
            }
            if(r-l+1==k)
            {
                maxSum=max(maxSum,sum);
                Map[nums[l]]--;
                sum=sum-nums[l];
                l++;
            }
            r++;
                
        }
        return maxSum;
    }
};
