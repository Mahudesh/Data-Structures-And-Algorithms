#include<bits/stdc++.h>

int lb(vector<int>& ans, int ele)
{
    int low=0;
    int high=ans.size()-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(ans[mid]>=ele)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return low;
}
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int>ans;
    ans.push_back(arr[0]);
    for(int i=1;i<n;i++)
    {
        if(arr[i]>ans.back())
        {
            ans.push_back(arr[i]);
        }
        else
        {
            //If It Is Not Increasing Then Check For Where I Can Insert In Formed Array
            int lowerbound=lb(ans,arr[i]);
            ans[lowerbound]=arr[i];
        }
        // int lowerbound=lb(ans,arr[i]);

    }
    return ans.size();
}
