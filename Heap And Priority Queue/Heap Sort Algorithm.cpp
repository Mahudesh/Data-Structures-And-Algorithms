#include <bits/stdc++.h> 
void heapify_down(vector<int>& arr, int ind, int last)
{
	int largest=ind;
	int leftChild=(2*ind)+1;
	int rightChild=(2*ind)+2;

	if(leftChild<=last && arr[largest]<arr[leftChild])
	largest=leftChild;
	if(rightChild<=last && arr[largest]<arr[rightChild])
	largest=rightChild;

	if(largest!=ind)
	{
		swap(arr[largest],arr[ind]);
		heapify_down(arr,largest,last);
	}

}
void buildMaxHeap(vector<int>& arr)
{
	int n=arr.size();
	int last=n-1;
	for(int i=(n/2)-1;i>=0;i--)
	{
		heapify_down(arr,i,last);
	}
}
vector<int> heapSort(vector<int>& arr, int n) 
{
	// Write your code here.
	buildMaxHeap(arr);
	int last=n-1;
	while(last>0)
	{
		swap(arr[0],arr[last]);
		last--;
		if(last>0)
		heapify_down(arr,0,last);
	}
	return arr;

}
