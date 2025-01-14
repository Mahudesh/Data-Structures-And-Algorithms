Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) 
    {
        
        // code here
        vector<int>prefixSum(arr.size(),0);
        vector<int>suffixSum(arr.size(),0);
        
        prefixSum[0]=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            prefixSum[i]=prefixSum[i-1]+arr[i];
        }
        suffixSum[arr.size()-1]=arr[arr.size()-1];
        for(int i=arr.size()-2;i>=0;i--)
        {
            suffixSum[i]=suffixSum[i+1]+arr[i];
        }
        for(int i=0;i<arr.size();i++)
        {
            if(prefixSum[i]==suffixSum[i])
            return i;
        }
        return -1;
    }
