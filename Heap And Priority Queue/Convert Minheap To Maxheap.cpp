void heapify_down(long *arr, int ind, int n)
{
    int largest=ind;
    int leftChild=(2*ind)+1;
    int rightChild=(2*ind)+2;

    if(leftChild<n && arr[largest]<arr[leftChild])
    largest=leftChild;

    if(rightChild<n && arr[largest]<arr[rightChild])
    largest=rightChild;

    if(largest!=ind)
    {
        swap(arr[largest],arr[ind]);
        heapify_down(arr,largest,n);
    }
    return;
}
void minHeapToMaxHeap(long *arr, int n)
{
    //Write your code here
    for(int i=(n/2)-1;i>=0;i--)
    {
        heapify_down(arr,i,n);
    }
}
