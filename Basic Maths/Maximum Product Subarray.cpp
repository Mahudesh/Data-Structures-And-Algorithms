class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        long long pref=1;
        long long suff=1;
        long long  ans=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            //Handle Zeros If Zero Occurs Then pref and suff Reinitiallized With 1
            if(pref==0) pref=1;
            if(suff==0) suff=1;
            pref=pref*nums[i];
            suff=suff*nums[nums.size()-1-i];
            ans=max(ans,max(pref,suff));
        }
        return (int)ans;
    }
};
