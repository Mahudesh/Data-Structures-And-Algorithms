public:
  int findMini(int arr[], int size)
  {
      int maxi=INT_MIN;
      for(int i=0;i<size;i++)
      {
          if(maxi<arr[i])
          {
              maxi=arr[i];
          }
      }
      return maxi;
  }
  int findSum(int arr[], int size)
  {
      int sum=0;
      for(int i=0;i<size;i++)
      {
          sum+=arr[i];
      }
      return sum;
  }
  bool isPossible(int arr[], int maxWeight, int d, int size)
  {
      int days=1;
      int sumOfWeight=0;
      for(int i=0;i<size;i++)
      {
          if(sumOfWeight+arr[i]<=maxWeight)
          {
              sumOfWeight+=arr[i];
          }
          else
          {
              days++;
              sumOfWeight=arr[i];
          }
      }
    //   if(sumOfWeight<=maxWeight)
    //   days++;
      if(days<=d)
      return true;
      return false;
  }
    int leastWeightCapacity(int arr[], int n, int d)
    {
        // code here
        
        int low=findMini(arr,n);
        int high=findSum(arr,n);
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(isPossible(arr,mid,d,n))
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
