#include <bits/stdc++.h> 
int flipBits(int* arr, int n) 
{
    // WRITE YOUR CODE HERE
    //Convert Into Kadane's Algorithm
    int countOnes=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
        {
            arr[i]=-1;
            countOnes++;
        }
        else
        {
            arr[i]=1;
        }
    }
    //Kadane's Algorithm
    int sum=0;
    int maxSum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum<0)
        sum=0;
        maxSum=max(sum,maxSum);
    }
    return maxSum+countOnes;
}
