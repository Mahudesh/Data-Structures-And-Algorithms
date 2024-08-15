class Solution {
public:
    int missingNumber(vector<int>& nums)
     {
        // int n=nums.size();
        // int ans=0;
        // for(int i=0;i<=n;i++)
        // {
        //     auto it=find(nums.begin(),nums.end(),i);
        //     if(it==nums.end())
        //     {
        //         ans=i;
        //         break;
        //     }
        // }
        // return ans;
        int n = nums.size();
        //Logic : Calculate Sum Of N Natural Numbers
        //Subtract it from individual sum of each numbers and their difference is the missing number
        int summation = (n*(n+1))/2;
        int sum = 0;
        for(auto it : nums)
        {
            sum+=it;
        }
        return summation-sum;
    }
};
