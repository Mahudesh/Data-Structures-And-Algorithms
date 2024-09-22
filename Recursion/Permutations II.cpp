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
        // i>0 for not  considering only one element in the array 
        // nums[i]==nums[i-1] for duplicates
        //!visitedEle[i-1] for checking previous duplicate is not taken
        //If previous duplicate is not taken then that previous duplicate can be taken into the array while generating permutations
        //So kindly avoid those
        //If previous duplicate is taken(visited) then we are not going to take that previous duplicate anymore
        //Which ultimately produces new permuations
        if(visitedEle[i]==true || i>0 && nums[i]==nums[i-1]&&!visitedEle[i-1])
        {
            continue;
        }
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
    vector<vector<int>> permuteUnique(vector<int>& nums)
     {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        vector<bool>visitedEle(nums.size(),false);
        permutation(nums,temp,visitedEle,ans);
        return ans;
    }
};
