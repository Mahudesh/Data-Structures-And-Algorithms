class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        int n=nums.size();
        double ans=INT_MIN;
        int l=0,r=0;
        double sum=0.0;
        while(r<n)
        {
            sum=sum+nums[r];

            if(r-l+1>k)
            {
                sum=sum-nums[l];
                l++;
            }

            if(r-l+1==k)
            {
                double avg=sum/(r-l+1);
                ans=max(ans,avg);
            }

            r++;
        }
        return ans;
    }
};
