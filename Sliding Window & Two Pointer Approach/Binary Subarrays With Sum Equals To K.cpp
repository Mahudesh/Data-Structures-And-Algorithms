#LeetCode: 930
class Solution {
public:
int countSubarrays(vector<int>&nums, int k)
{
    int l=0;
    int r=0;
    int cnt=0;
    int odds=0;
    while(r<nums.size())
    {
        if(nums[r]%2!=0){
        odds++;
        }
        while(odds>k && l<=r)
        {
            if(nums[l]%2!=0) {
            odds--;
            }
            l++;
        }
       
            cnt=cnt+(r-l+1);
        
        r++;
    }
    return cnt;
}
    int numberOfSubarrays(vector<int>& nums, int k)
     {
        //Sliding Window And Two Pointer Approach
        int a=countSubarrays(nums,k-1);
        int b=countSubarrays(nums,k);
        return b-a;

    }
};
