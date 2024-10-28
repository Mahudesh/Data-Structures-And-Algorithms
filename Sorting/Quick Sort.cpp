#include<bits/stdc++.h>
using namespace std;
int findPivot(vector<int>&arr, int low, int high)
{
    int pivot=arr[low];
    int i=low;
    int j=high;
    // while(arr[i]<=pivot && i<=n-1)
    while(i<j)
    {
        while(arr[i]<=pivot && i<=high-1)
        {
            i++;
        }
        while(arr[j]>pivot && j>=low+1)
        {
            j--;
        }
        if(i<j)
        swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}
void quickSort(vector<int>&arr, int low, int high)
{
    if(low<high)
    {
        int pivotIndex=findPivot(arr,low,high);
        quickSort(arr,low,pivotIndex-1);
        quickSort(arr,pivotIndex+1,high);
    }
}
int main()
{
    vector<int>arr={3,5,2,7,6,8,1};
    quickSort(arr,0,arr.size()-1);
    for(auto it: arr)
    cout<<it<<" ";
}
