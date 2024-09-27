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

        //Better Approach
        // int sum=1;
        // int maxProd=INT_MIN;
    
        // for(int i=0;i<nums.size();i++)
        // {
        //     sum=sum*nums[i];
        //     maxProd=max(maxProd,sum);
        //     if(sum==0)
        //     {
        //         sum=1;
        //     }
        // }
        //     sum=1;
        // for(int i=nums.size()-1;i>=0;i--)
        // {
        //     sum=sum*nums[i];
        //     maxProd=max(maxProd,sum);
        //     if(sum==0)
        //     {
        //         sum=1;
        //     }
        // }
        // return maxProd;
       

        //BruteForce approach
        // int prod=1;
        // int maxProd=INT_MIN;
        // for(int i=0;i<nums.size();i++)
        // {
        //     prod=1;
        //     for(int j=i;j<nums.size();j++)
        //     {
        //         prod=prod*nums[j];
        //         maxProd=max(maxProd,prod);
        //     }
        // }
        // return maxProd;
    }
};
