int cnt=0;
void mergeArray(vector<int>&arr,int low, int mid, int high)
{
    int left=low;
    int right=mid+1;
    vector<int>temp;
    while(left<=mid && right<=high)
    {
        if(arr[left]>arr[right])
        {
            cnt=cnt+(mid-left+1);
            left++;
        }
        else
        {
            right++;
        }
    }
    left=low;
    right=mid+1;
    while(left<=mid && right<=high)
    {
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right++]);
        }
    }
    while(left<=mid)
    {
        temp.push_back(arr[left++]);
    }
    while(right<=high)
    {
        temp.push_back(arr[right++]);
    }
    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[i-low];
    }
}
void mergeSort(vector<int>&a, int low, int high)
{
    if(low>=high) return;
    int mid=(low+high)/2;
    mergeSort(a,low,mid);
    mergeSort(a,mid+1,high);
    mergeArray(a,low,mid,high);
}
int numberOfInversions(vector<int>&a, int n)
 {
    // Write your code here.
    // int c=0;
    // for(int i=0;i<a.size();i++)
    // {
    //     for(int j=i+1;j<a.size();j++)
    //     {
    //         if(a[i]>a[j])
    //         {
    //             c++;
    //         }
    //     }
    // }
    // return c;

    mergeSort(a,0,a.size()-1);
    return cnt;
}
