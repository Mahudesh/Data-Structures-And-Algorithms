#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& nums, int k){
    // Write your code here
    unordered_map<int,int>Map;
    int sum = 0;
    int len = 0;
    for(int i=0;i<nums.size();i++)
    {
        sum = sum+nums[i];

    if(sum == k)
        {
            len = i+1;
        }

        int rem = sum - k;

        if(Map.find(rem)!=Map.end())
        {
            int lentemp = i - Map[rem];
            len = max(len,lentemp);
        }
        if(Map.find(sum) == Map.end())
        Map[sum]=i;
    }
    if(len == 0 ) return 0;
    return len;
}
