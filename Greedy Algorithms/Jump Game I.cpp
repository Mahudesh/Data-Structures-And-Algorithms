class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int maxIndex=0;
        for(int i=0;i<nums.size();i++)
        {
            //If I Am At Index But The Maximum Index You Have Previously Reached Is Less Than i
            //Then As A Person How Could You Come Here? Its Impossible
            //So Return False
            //Else Return True
            if(maxIndex<i)
            return false;
            maxIndex=max(maxIndex,i+nums[i]);
        }
        return true;
    }
};
