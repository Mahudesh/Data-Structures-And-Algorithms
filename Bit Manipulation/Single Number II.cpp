class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        // map<int,int>Map;
        // int ans=0;
        // for(int ele : nums)
        // {
        //     Map[ele]++;
        // }
        // for(auto it : Map)
        // {
        //     if(it.second==1)
        //     {
        //         ans=it.first;
        //     }
        // }
        // return ans;
        //Optimal Approach
        int ones=0;
        int twos=0;
        for(int i=0;i<nums.size();i++)
        {
            ones=(ones^nums[i])&(~twos);
            twos=(twos^nums[i])&(~ones);
        }
        return ones;
    }
};
