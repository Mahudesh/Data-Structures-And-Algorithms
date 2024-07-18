#LeetCode: 209
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int start=-1;
        int end=-1;
        int l=0;
        int r=0;
        int sum=0;
        int minlength=INT_MAX;
        while(r<nums.size())
        {
            sum+=nums[r];
            while(sum>=target)
            {
                if(minlength>r-l+1)
                {
                  minlength=r-l+1;
                }
                sum-=nums[l];
                l++;
            }
            r++;
        }
        if(minlength==INT_MAX)
         return 0;
        return minlength;
    }
};
