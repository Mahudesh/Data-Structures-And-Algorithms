class Solution {
public:
void reverse(vector<int>& nums, int l, int r)
{
      while(l<r)
        {
            swap(nums[l],nums[r]);
            l++;
            r--;
        }
}

    void nextPermutation(vector<int>& nums) 
    {
        int ind=-1;
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                ind=i;
                break;
            }
        }
        if(ind==-1)
        {
            reverse(nums,0,nums.size()-1);
            return;
            
        }
        for(int i=nums.size()-1;i>=ind+1;i--)
        {
            if(nums[i]>nums[ind])
            {
                swap(nums[i],nums[ind]);
                break;
            }
        }
        int l=ind+1;
        int r=nums.size()-1;
        reverse(nums,l,r);
      
    }
};
