class Solution {
public:
bool isOk(vector<int>& nums, int ind)
{
    int leftChild=(2*ind)+1;
    int rightChild=(2*ind)+2;

    if(leftChild<nums.size() && nums[ind]>nums[leftChild])
    return false;

    if(rightChild<nums.size() && nums[ind]>nums[rightChild])
    return false;

    return true;

}
    bool isHeap(vector<int>& nums) 
    {
        int n=nums.size();
        for(int i=(n/2)-1;i>=0;i--)
        {
            if(!isOk(nums,i))
            return false;
        }
        return true;
    }
};
