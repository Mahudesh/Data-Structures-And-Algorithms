#include <bits/stdc++.h> 
vector<int> maximumsumSubarray(vector<int> &arr , int n)
{
   int sum=0;
   int maxSum=INT_MIN;
   int start=0;
   int fstart=0;
   int end=0;
   for(int i=0;i<n;i++)
   {
       sum+=arr[i];
       if(sum>maxSum)
       {
           maxSum=sum;
           start=fstart;
           end=i;
       }
      else if(sum==maxSum)
       {
           int len1=end-start+1;
           int len2=i-fstart+1;
           if(len1<len2)
           {
               start=fstart;
               end=i;
           }
       }
       if(sum<0)
       {
           sum=0;
           fstart=i+1;
       }
   }
       vector<int>ans;
       for(int i=start;i<=end;i++)
       {
           ans.push_back(arr[i]);
       }
       return ans;
   
}
//1 2 5 -7 -2 3 1 1 1 1 1
