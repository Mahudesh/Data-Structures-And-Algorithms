Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) 
    {
        // code here
        int n=arr.size();
        vector<int>ans1(n,1);
        vector<int>ans2(n,1);
        
        for(int i=1;i<arr.size();i++)
        {
            ans1[i]=ans1[i-1]*arr[i-1];
        }
        
        for(int i=n-2;i>=0;i--)
        {
            ans2[i]=ans2[i+1]*arr[i+1];
        }
        
        for(int i=0;i<n;i++)
        {
            ans1[i]=ans1[i]*ans2[i];
        }
        return ans1;
        
