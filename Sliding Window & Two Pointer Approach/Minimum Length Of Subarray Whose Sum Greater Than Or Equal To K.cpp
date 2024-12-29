// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int target;
    int n;
    cin>>target>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int l=0;
    int r=0;
    int minLen=INT_MAX;
    int sum=0;
    while(r<arr.size())
    {
        sum=sum+arr[r];
        while(sum>=target && l<=r)
        {
            if(r-l+1 < minLen)
            {
                minLen=r-l+1;
            }
            sum=sum-arr[l];
            l++;
        }
        r++;
    }
    if(minLen==INT_MAX)
    cout<<0;
    else
    cout<<minLen;
}
