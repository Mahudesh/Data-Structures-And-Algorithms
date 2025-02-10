#include <bits/stdc++.h> 
void heapify_down(vector<int>& arr, int ind)
{
    int smallest=ind;
    int leftChild=(2*ind)+1;
    int rightChild=(2*ind)+2;

    if(leftChild<arr.size() && arr[smallest]>arr[leftChild])
    smallest=leftChild;

    if(rightChild<arr.size() && arr[smallest]>arr[rightChild])
    smallest=rightChild;

    if(smallest!=ind)
    {
        swap(arr[ind],arr[smallest]);
        heapify_down(arr,smallest);
    }
    return;
}
vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    int n=arr.size();
    for(int i=(n/2)-1;i>=0;i--)
    {
        heapify_down(arr,i);
    }
    return arr;
}
