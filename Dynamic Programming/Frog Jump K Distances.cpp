 Solution {
  public:
  int helper(int k, int ind, vector<int>&arr,int ans,vector<int>&dp)
  {
      if(ind==0)
      return 0;
      if(dp[ind]!=-1)
      return dp[ind];
      int left=0;
      for(int i=1;i<=k;i++)
      {
        //   int left=0;
          if(ind>=i)
          {
              left= helper(k,ind-i,arr,ans,dp)+abs((arr[ind]-arr[ind-i]));
              
          }
          ans=min(ans,left);
      }
      return dp[ind]=ans;
    //   int left=helper(k,ind-1,arr)+abs((arr[ind]-arr[ind-1]));
    //   int right=INT_MAX;
    //   if(ind>1)
    //   right=helper(k,ind-2,arr)+abs((arr[ind]-arr[ind-2]));
      
    //   return min(left,right);
  }
    int minimizeCost(int k, vector<int>& arr) 
    {
        // Code here
        int ans=INT_MAX;
        vector<int>dp(arr.size(),-1);
        return helper(k,arr.size()-1,arr,ans,dp);
        
        //Tabulization
        // vector<int>dp(arr.size(),0);
        // dp[0]=0;
        // for(int i=1;i<arr.size();i++)
        // {
        //     int ans=INT_MAX;
        //     for(int j=1;j<=k;j++)
        //     {
        //         if(i>=j)
        //         {
        //             int left=dp[i-j]+abs(arr[i]-arr[i-j]);
        //             ans=min(ans,left);
        //         }
        //     }
        //     dp[i]=ans;
        // }
        // return dp[arr.size()-1];
    
    }
};
