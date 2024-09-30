class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        // map<int,int>Map;
        // int ans=0;
        // for(int ele : nums)
        // {
        //     Map[ele]++;
        // }
        // for(auto pair : Map)
        // {
        //     if(pair.second==1)
        //     {
        //         ans=pair.first;
        //     }
        // }
        // return ans;
        // 0^0=0 and 0^1=1
        // int xor1 = 0;
        // for(auto it : nums)
        // {
        //     xor1 = xor1^it;
        // }
        // return xor1;
        if(nums.size()==1)
        return nums[0];

        int low=1;
        int high=nums.size()-2;
        if(nums[0]!=nums[1])
        return nums[0];
        if(nums[nums.size()-1]!=nums[nums.size()-2])
        return nums[nums.size()-1];
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
            return nums[mid];
            if((mid%2==0 && nums[mid]==nums[mid+1]) || (mid)%2!=0 && nums[mid]==nums[mid-1])
            {
                low=mid+1;
            }
            else if(((mid%2!=0) && nums[mid]==nums[mid+1]) || ((mid)%2==0 && nums[mid]==nums[mid-1]))
            {
                high=mid-1;
            }

        }
        return -1;
    }
};
