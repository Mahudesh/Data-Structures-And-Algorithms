class NumArray {
public:
vector<int>prefixSum;
    NumArray(vector<int>& nums) 
    {
        prefixSum.resize(nums.size());
        prefixSum[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            prefixSum[i]=nums[i]+prefixSum[i-1];
        }
    }
    
    int sumRange(int left, int right)
     {
        // -2 -2 1 -4 -2 -3
        //  0  1 2  3  4  5
        //If Total Length=a
        //Then If The Range Length Is B
        //Then Outside Range Length Will be C
        //To Find Range Length Find Ultimately Full Length-Outside Range Length(a-c);
        if(left==0)
        {
            return prefixSum[right];
        }
        return prefixSum[right]-prefixSum[left-1];
    }   
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
