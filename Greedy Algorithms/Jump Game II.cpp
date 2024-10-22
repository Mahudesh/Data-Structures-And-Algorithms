class Solution {
public:
    int jump(vector<int>& nums) 
    {
      int ans=0;
      int farthest=0;
      int curr=0;
      int jumps=0;
      for(int i=0;i<nums.size();i++)
      {
        farthest=max(farthest,nums[i]+i);
        if(curr>=nums.size()-1)
        {
            return jumps;
        }
        if(curr==i)
        {
            jumps++;
            curr=farthest;
        }
      }  
      return 0;
    }
};
