#LeetCode: 992
class Solution {
public:
int subarraysWith_LesserOrEqualToK(vector<int>nums, int k)
{
    int cnt=0;
    unordered_map<int,int>Map;
    int l=0;
    int r=0;
    while(r<nums.size())
    {
        Map[nums[r]]++;
        
            while(Map.size()>k)
            {
                Map[nums[l]]--;
                if(Map[nums[l]]==0)
                 Map.erase(nums[l]);
                l++;
            }
            cnt=cnt+(r-l+1);
        
        r++;
    }
    return cnt;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        // int cnt=0;
        // for(int i=0;i<nums.size();i++)
        // {
        //         set<int>st;
        //     for(int j=i;j<nums.size();j++)
        //     {
        //         st.insert(nums[j]);
        //         if(st.size()==k)
        //         cnt++;
        //         else if(st.size()>k)
        //         break;
        //     }
        // }
        // return cnt;

        int a=subarraysWith_LesserOrEqualToK(nums,k);
        int b=subarraysWith_LesserOrEqualToK(nums,k-1);
        return a-b;
    }
};
