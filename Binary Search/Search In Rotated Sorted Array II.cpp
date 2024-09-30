class Solution {
public:
    int search(vector<int>& arr, int target) 
    {
        int low=0;
        int high=arr.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]==target) return mid;
            //Check For Which Half Of The Array Is Sorted
            //Left Sorted Array Condition
            if(arr[low]<=arr[mid])
            {
                //Condition For Element To Be Present In Left Side
                if(arr[low]<=target && target<=arr[mid])
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            //Right Sorted Array Condition
            else if(arr[mid]<=arr[high])
            {
                //Condition For ELement To Be Present In Right Side
                if(arr[mid]<=target && target<=arr[high])
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};
