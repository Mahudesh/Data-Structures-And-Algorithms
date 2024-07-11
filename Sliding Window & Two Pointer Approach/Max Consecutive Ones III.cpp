#LeetCode 1004
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        //Convert The Logic Into Longest Subarray With Atmost K Zeros
        int zeros=0;
        //Sliding Window Approach
        //A Valid Sliding Window Should Have Atmost K Zeros
        //If So Update The Maximum Length Of The Subarray
        int l=0;
        int r=0;
        int len=0;
       while(r<nums.size())
       {
        if(nums[r]==0)
        {
            zeros++;
        }
        if(zeros<=k)
        {
            len=max(len,r-l+1);
        }
        else
        {
            while(zeros>k)
            {
                //If We See Any Zeros While Shrinking Then Reduce The Zero In Window Size
                //Move L Forward
                if(nums[l]==0)
                {
                    zeros--;
                }
                l++;
            }
        }
        r++;
       }
       return len;
    }
};
