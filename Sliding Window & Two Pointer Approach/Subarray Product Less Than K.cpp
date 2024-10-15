class Solution {
public:

    int numSubarrayProductLessThanK(vector<int>& nums, int k)
     {
        int l=0;
        int r=0;
        int cnt=0;
        int prod=1;
        while(r<nums.size())
        {
            prod=prod*nums[r];
            while(prod>=k && l<=r)
            {
                prod=prod/nums[l];
                l++;
            }
            cnt=cnt+(r-l)+1;
            r++;
        }
        return cnt;
    }
};
