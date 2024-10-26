#include<bits/stdc++.h>
pair<int,int> twoSum(vector<int>& arr, int n, int target) {

    // Write your code here
    unordered_map<int,int>Map;
    // int sum=0;
    // Map[0]=1;
    pair<int,int>result={-1,-1};
    for(int i=0;i<n;i++)
    {
        int ele=arr[i];
        int moreNeeded=target-ele;
        if(Map.find(moreNeeded)!=Map.end())
        {
            // return {Map[moreNeeded],i};
            int j=Map[moreNeeded];
            //Comparing Current Pair With Previous Pair Which One Is Lexicographically Smallest One
            if(make_pair(j,i)<result || result.first==-1)
            {
                result={j,i};
            }
        }
        if(Map.find(ele)==Map.end())
        Map[ele]=i;
    }
    return result;
}
