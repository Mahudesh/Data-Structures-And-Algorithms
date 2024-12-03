class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
     {
        // set<vector<int>>st;
        // for(int i=0;i<nums.size();i++)
        // {
        //     for(int j=i+1;j<nums.size();j++)
        //     {
        //         unordered_set<long long>hashSet;
        //         for(int k=j+1;k<nums.size();k++)
        //         {
        //             long long sum=nums[i]+nums[j];
        //             sum+=nums[k];
        //             long long fourth=target-sum;
        //             if(hashSet.find(fourth)!=hashSet.end())
        //             {
        //                 vector<int>temp={nums[i],nums[j],nums[k],(int)fourth};
        //                 sort(temp.begin(),temp.end());
        //                 st.insert(temp);
        //             }

        //             hashSet.insert(nums[k]);
        //         }
        //     }
        // }
        // vector<vector<int>>ans(st.begin(),st.end());
        // return ans;

        //Optimal Approach

        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int i=0;
        int j=0;
        int k=0;
        int l=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            continue;
            for(int j=i+1;j<nums.size();j++)
            {
                if(j>i+1 && nums[j]==nums[j-1])
                continue;
                k=j+1;
                l=nums.size()-1;
                while(k<l)
                {
                    long long sum=nums[i]+nums[j];
                    sum+=nums[k]+nums[l];
                    if(sum<target)
                    {
                        k++;
                    }
                    else if(sum>target)
                    {
                        l--;
                    }
                    else
                    {
                        vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1])
                        {
                            k++;
                        }
                        while(k<l && nums[l]==nums[l+1])
                        {
                            l--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};