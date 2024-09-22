#include <bits/stdc++.h> 
int a=0;
 void subset(vector<int> &arr,int n,int k,int sum,int index)
 {
   //  a=0;
     if(index==n)
     {
         if(sum==k)
         {
         a++;
         }
         return;
     }
     subset(arr,n,k,sum,index+1);
     subset(arr,n,k,sum+arr[index],index+1);

 }
bool subsetSumToK(int n, int k, vector<int> &arr) 
{
    subset(arr,n,k,0,0);
    if(a>0)
    {
        a=0;
    return true;
    }
    return false;
}
