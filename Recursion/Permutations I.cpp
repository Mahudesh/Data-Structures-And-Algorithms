class Solution {
public:
void permutation(vector<int>&nums,vector<int>&temp,vector<bool>& visitedEle,vector<vector<int>>&ans)
{
    if(temp.size()==nums.size())
    {
        ans.push_back(temp);
        return;
    }
    for(int i=0;i<nums.size();i++)
    {
        if(visitedEle[i]==false)
        {
            temp.push_back(nums[i]);
            visitedEle[i]=true;
            permutation(nums,temp,visitedEle,ans);
            visitedEle[i]=false; 
            temp.pop_back();
        }
    }
}
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>>ans;
        vector<int>temp;
        vector<bool>visitedEle(nums.size(),false);
        permutation(nums,temp,visitedEle,ans);
        return ans;
    }
};
