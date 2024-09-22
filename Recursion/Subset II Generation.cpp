class Solution {
public:
void powerset(vector<int>&nums,int ind,vector<int>&temp,vector<vector<int>>&myset)
{
    //To Generate Initial Empty Array
    myset.push_back(temp);
   
    for(int i=ind;i<nums.size();i++)
    {
        // 1 1 2 If it is like this then nums[i]==nums[i+1] then we skip the duplicate and move to next element
        if(i!=ind && nums[i]==nums[i-1])//Skip Duplicates
        continue;
        temp.push_back(nums[i]);
        powerset(nums,i+1,temp,myset);
        temp.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<int>temp;
        vector<vector<int>> myset;
        //It should be sort for ordering duplicate values nearby
        sort(nums.begin(),nums.end());
        powerset(nums,0,temp,myset);
        return myset;
    }
};
