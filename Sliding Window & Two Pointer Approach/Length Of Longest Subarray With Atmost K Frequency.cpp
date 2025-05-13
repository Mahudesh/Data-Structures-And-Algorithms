class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) 
    {
        int n=nums.size();
        int l=0,r=0;
        unordered_map<int,int>Map;
        int extrafreq=0;
        int maxLen=0;
        while(r<n)
        {
            Map[nums[r]]++;

            if(Map[nums[r]]>k)
            {
                extrafreq++;
                while(extrafreq>0 && l<=r)
                {
                    if(Map[nums[l]]>k)
                    {
                        extrafreq--;
                    }
                    Map[nums[l]]--;
                    l++;
                }
            }
            maxLen=max(maxLen,r-l+1);
            r++;

        }    
        return maxLen;
    }
};
