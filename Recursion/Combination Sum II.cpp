class Solution {
public:
void subset(vector<int>&candidates,int ind, int sum,int target,vector<int>&temp,vector<vector<int>>&ans)
{
    if(sum==target)
    {
        ans.push_back(temp);
        return;
    }
    for(int i=ind;i<candidates.size();i++)
    {
        if(i>ind && candidates[i]==candidates[i-1])//Skip Duplicates
        continue;
        if(sum+candidates[i]>target)
        break;
        temp.push_back(candidates[i]);
        subset(candidates,i+1,sum+candidates[i],target,temp,ans);
        temp.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
     {
        vector<int>temp;
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        subset(candidates,0,0,target,temp,ans);
        return ans;
    }
};
