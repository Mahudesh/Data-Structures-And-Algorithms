class Solution {
public:
void reverse(vector<int>&arr, int l, int r)
{
    while(l<=r)
    {
        swap(arr[l],arr[r]);
        l++;
        r--;
    }
}
    void rotate(vector<int>& nums, int k) 
    {
        int n=nums.size();
        int r=k%n;
        reverse(nums,0,n-r-1);
        reverse(nums,n-r,n-1);
        reverse(nums,0,n-1);
    }
};
