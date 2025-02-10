class Solution {
public:
void heapify_down(vector<int>& nums, int ind)
{
    int smallest=ind;
    int leftChild=(2*ind)+1;
    int rightChild=(2*ind)+2;

    if(leftChild<nums.size() && nums[leftChild]<nums[smallest])
    smallest=leftChild;

    if(rightChild<nums.size() && nums[rightChild]<nums[smallest])
    smallest=rightChild;

    if(smallest!=ind)
    {
        swap(nums[ind],nums[smallest]);
        heapify_down(nums,smallest);
    }
    return;
}
void heapify_up(vector<int>& nums, int ind)
{
    int parent=(ind-1)/2;
    if(ind>0)
    {
        if(nums[ind]<nums[parent])
        {
            swap(nums[ind],nums[parent]);
            heapify_up(nums,parent);
        }
    }
    return;
}
    void heapify(vector<int> &nums, int ind, int val) 
    {
        if(nums[ind]<val)
        {
            nums[ind]=val;
            heapify_down(nums,ind);
        }
        else
        {
            nums[ind]=val;
            heapify_up(nums,ind);
        }
    }
};
