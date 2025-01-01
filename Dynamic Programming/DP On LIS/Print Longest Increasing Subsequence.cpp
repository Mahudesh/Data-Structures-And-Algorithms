 vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) 
    {
        // Code here
        vector<int>dp(n,1);
        vector<int>hash(n);
        int last_index=0;
        int maxiLen=1;
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int prev_ind=0;prev_ind<=i-1;prev_ind++)
            {
                if(arr[prev_ind]<arr[i])
                {
                    if(dp[prev_ind]+1 > dp[i])
                    {
                        dp[i]=dp[prev_ind]+1;
                        hash[i]=prev_ind;
                    }
                }
            }
            if(maxiLen<dp[i])
            {
                maxiLen=dp[i];
                last_index=i;
            }
        }
        vector<int>ans;
        ans.push_back(arr[last_index]);
        while(hash[last_index]!=last_index)
        {
             last_index=hash[last_index];
            ans.push_back(arr[last_index]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
