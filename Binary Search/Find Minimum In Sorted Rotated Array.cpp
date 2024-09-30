  int findMin(vector<int>& arr)
    {
        // complete the function here
        int low=0;
        int high=arr.size()-1;
        int ele=INT_MAX;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[low]<=arr[mid])
            {
                // ele=arr[low];
                ele=min(ele,arr[low]);
                low=mid+1;
            }
            else
            {
                ele=min(ele,arr[mid]);
                high=mid-1;
            }
        }
        return ele;
    }
