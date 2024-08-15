class Solution {
public:
void reverse(vector<int>&nums, int left, int right)
{
    while(left<=right)
    {
        swap(nums[left],nums[right]);
        left++;
        right--;
    }
}
    void rotate(vector<int>& nums, int k) 
    {
        // for(int i=0;i<k;i++)
        // {
        //      int temp=nums[nums.size()-1];
        //     nums.pop_back();
        //     nums.insert(nums.begin(),temp);

        // }
        int n=nums.size();
        k=k%n;
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);
    }
};
