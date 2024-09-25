long long subarraySum(vector<int>& arr) \
    {
        // Your code goes here
        //Find Contribution Of Each Element In Array And Multiply By The Value
        
        long long startcount=0;
        long long endcount=0;
        long long tot=0;
        long long mod=1e9+7;
        for(long long i=0;i<arr.size();i++)
        {
            startcount=i+1;
            endcount=arr.size()-i;
            
            tot=(tot+(arr[i]*startcount*endcount))%mod;
            
        }
        return tot;
    }
