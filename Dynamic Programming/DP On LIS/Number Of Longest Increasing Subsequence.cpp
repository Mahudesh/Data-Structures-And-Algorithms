class Solution {
public:
    int findNumberOfLIS(vector<int>& arr)
     {
        int n=arr.size();
        vector<int>dp(n,1);
        vector<int>cnt(n,1);
        int maxi=1;
        for(int i=0;i<n;i++)
        {
            for(int prev_ind=0;prev_ind<=i-1;prev_ind++)
            {
                if(arr[i]>arr[prev_ind])
                {
                    if(dp[prev_ind]+1 > dp[i])
                    {
                        dp[i]=1+dp[prev_ind];
                        //If There Is New Length Formed Just Inherit The Previous Count
                        cnt[i]=cnt[prev_ind];
                    }
                    else if(dp[prev_ind]+1 == dp[i])
                    {
                        //If The Same Length Again Appears Then For Sure Multiple Count Of LIS Is There
                        //Hence Append The Previous Count Of LIS
                        cnt[i]=cnt[i]+cnt[prev_ind];
                    }
                }
            }
            maxi=max(maxi,dp[i]);
        }
        int nos=0;
        //There Can Be Multiple Same Length LIS
        //So Count All Of Those Which Occuring In The dp Array
        for(int i=0;i<n;i++)
        {
            if(dp[i]==maxi)
            nos=nos+cnt[i];
        }
        return nos;
    }
};
