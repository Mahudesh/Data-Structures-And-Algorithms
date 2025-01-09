void mergeArray(vector<int>& arr, int low, int mid, int high)
{
    int left=low;
    int right=mid+1;
    vector<int>temp;
    while(left<=mid && right<=high)
    {
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
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

void mergeSort(vector<int>& nums1, int low, int high)
{
    if(low>=high)
    return;
    int mid=(low+high)/2;
    mergeSort(nums1,low,mid);
    mergeSort(nums1,mid+1,high);
    mergeArray(nums1,low,mid,high);
}
double median(vector<int>& nums1, vector<int>& nums2)
 {
	// Write your code here.
	//  int i=nums1.size()-1;
    //     int j=0;
    //     while(i>=0 && j<nums2.size())
    //     {
    //         if(nums1[i]>nums2[j])
    //         {
    //             swap(nums1[i],nums2[j]);
    //             i--;
    //             j++;
    //         }
    //         else
    //         {
    //             break;
    //         }
    //     }
    //     mergeSort(nums1,0,nums1.size()-1);
    //     mergeSort(nums2,0,nums2.size()-1);
    //     j=0;
    //     while(j<nums2.size())
    //     {
    //         nums1.push_back(nums2[j]);
    //         j++;
    //     }
    //     if(nums1.size()%2==0)
    //     {
    //         int n=nums1.size();
    //         int med=nums1[n/2] + nums1[(n/2)-1];
    //         return (double)(med/2.0);
    //     }
    //     else
    //     {
    //         int n=nums1.size();
    //         return (double)nums1[n/2];
    //     }

        //Optimal Approach
        int n1=nums1.size();
        int n2=nums2.size();
        if(n1>n2)
        return median(nums2,nums1);
        int totSize=n1+n2;
        int low=0;
        int high=n1;
        int size=(n1+n2+1)/2;
        while(low<=high)
        {
            int mid1=(low+high)/2;
            int mid2=size-mid1;

            int l1=INT_MIN,l2=INT_MIN;
            int r1=INT_MAX, r2=INT_MAX;

            if(mid1<nums1.size()) r1=nums1[mid1];
            if(mid2<nums2.size()) r2=nums2[mid2];

            if(mid1-1>=0) l1=nums1[mid1-1];
            if(mid2-1>=0) l2=nums2[mid2-1];

            if(l1<=r2 && l2<=r1)
            {
                if(totSize%2==0)
                {
                    return (double)(max(l1,l2) + min(r1,r2))/2.0;
                }
                else
                {
                    return (max(l1,l2));
                }
            }
            else if(l1>r2)
            {
                high=mid1-1;
            }
            else
            {
                low=mid1+1;
            }
        }
        return 0;
}
