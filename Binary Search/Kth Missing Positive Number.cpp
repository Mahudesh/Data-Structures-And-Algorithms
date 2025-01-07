int missingK(vector < int > arr, int n, int k) 
{
    int low=0;
    int high=arr.size()-1;
    while(low<=high)
    {
        //Look For The Smallest/Closest Where There Is Lesser Missing Number Compared To K
        int mid=low+(high-low)/2;
        int missing = arr[mid]-(mid+1);
        if(missing>=k)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return low+k;
}
