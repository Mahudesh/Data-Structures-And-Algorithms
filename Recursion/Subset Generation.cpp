class Solution {
public:
   void subset(vector<int>&nums,int i,int n,vector<int>temp,vector<vector<int>>&ans)
    {
        if(i==n)
        {
            ans.push_back(temp);
            return;
        }
        subset(nums,i+1,n,temp,ans);
        temp.push_back(nums[i]);
        subset(nums,i+1,n,temp,ans);
        temp.pop_back();

    }
    vector<vector<int>> subsets(vector<int>& nums)
     {
        vector<int>temp;
        vector<vector<int>> ans;
        subset(nums,0,nums.size(),temp,ans);
        return ans;
    }
};
