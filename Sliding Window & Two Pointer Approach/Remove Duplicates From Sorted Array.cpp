class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        // set<int>sets;
        // for(int i=0;i<nums.size();i++)
        // {
        //     sets.insert({nums[i]});
        // }
        // nums.clear();
        // vector<int>temp(sets.begin(),sets.end());
        // for(int i=0;i<temp.size();i++)
        // {
        //     nums.push_back(temp[i]);
        // }
        // return nums.size();

        //Optimal
        int size=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[size-1])
            {
                nums[size]=nums[i];
                size++;
            }
        }
        return size;

    }
};
