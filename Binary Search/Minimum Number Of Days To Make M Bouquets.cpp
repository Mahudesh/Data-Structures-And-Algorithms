public:
  int isPossible(vector<int>& arr, int maxDays, int K, int M)
  {
      int flowers=0;
      int cnt=0;
      int bouquets=0;
      for(int i=0;i<arr.size();i++)
      {
          if(arr[i]<=maxDays)
          {
              cnt++;
          }
          else
          {
              cnt=0;
          }
          if(cnt==K)
          {
              bouquets++;
              cnt=0;
          }
      }
      if(bouquets>=M)
      return true;
      return false;
  }
    int solve(int M, int K, vector<int> &bloomDay)
    {
      // Code here
      if(M*K > bloomDay.size())
      return -1;
      int low=*min_element(bloomDay.begin(),bloomDay.end());
      int high=*max_element(bloomDay.begin(),bloomDay.end());
      while(low<=high)
      {
          int mid=(low+high)/2;
          if(isPossible(bloomDay,mid,K,M))
          {
              high=mid-1;
          }
          else
          {
              low=mid+1;
          }
      }
      return low;
