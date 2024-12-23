class Solution {
public:
// int helper(vector<int>& nums,int ind,int sum, int target)
// {
//     if(ind==0)
//     {
//         if(sum+nums[ind]==target || sum-nums[ind]==target)
//         return 1;
//         return 0;
//     }
//    int add=helper(nums,ind-1,sum+nums[ind],target);
//    int sub=helper(nums,ind-1,sum-nums[ind],target);

//    return add+sub;
// }
int helper(vector<int>& nums, int ind, int target)
{
    if(ind==0)
    {
        if(nums[ind]==0 && target==0)
        return 2;
        if(target==0 || target==nums[0])
        return 1;
        return 0;

    }
    int notPick=0+helper(nums,ind-1,target);
    int pick=0;
    if(nums[ind]<=target)
    {
        pick=helper(nums,ind-1,target-nums[ind]);
    }
    return notPick+pick;
}
    int findTargetSumWays(vector<int>& nums, int t) 
    {
        // return helper(nums,nums.size()-1,0,target);

        //This Problem Is Similar To S1-S2==D Where S1>=S2

        //Assign Some Positive Values In S1
        //Assign Some Negative Values In S2 By Taking Common Out (-)
        //Since We Are Assigning Positive To S1 It Validates The Condition S1>=s2
        //Perform S1-S2==Target

        int totSum=accumulate(nums.begin(),nums.end(),0);
        if(totSum-t<0 || (totSum-t)%2!=0)
        return 0;
        return helper(nums,nums.size()-1,(totSum-t)/2);
    }
};
