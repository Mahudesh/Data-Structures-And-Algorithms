#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>arr={-2,1,-3,4,-1,2,1,-5,4};
    int sum=0;
    int maxSum=INT_MIN;
    int start=-1,end=-1;
    int fstart=-1;
    for(int i=0;i<arr.size();i++)
    {
        sum+=arr[i];
        if(maxSum<sum)
        {
            maxSum=sum;
            start=fstart;
            end=i;
        }   
        if(sum<0)
        {
            sum=0;
            fstart=i+1;
        }
    }
    for(int i=start;i<=end;i++)
    cout<<arr[i]<<" ";
    // cout<<maxSum;
}
