class Solution {
public:
void subsetsum(vector<int>candidates,int ind,int target,vector<vector<int>>&ans,vector<int>&temp)
{
    if(target==0)
    {
        ans.push_back(temp);
        return;
    }
    else if(ind==candidates.size() || target<0)
    {
        return;
    }
    subsetsum(candidates,ind+1,target,ans,temp);
    temp.push_back(candidates[ind]);
    subsetsum(candidates,ind,target-candidates[ind],ans,temp);
    temp.pop_back();
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
     {
        vector<vector<int>>ans;
        vector<int>temp;
        subsetsum(candidates,0,target,ans,temp);
        return ans;
    }
};
