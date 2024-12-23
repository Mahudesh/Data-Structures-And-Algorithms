class Solution {
public:
int helper(vector<int>& coins, int ind, int target, vector<vector<int>>& dp)
{
    // if(target<0)
    // return -1;
    // if(target==0)
    // return 1;
    if(ind==0)
    {
        if(target%coins[ind]==0)
        {
            return target/coins[ind];
        }
        return 1e9;
    }
    if(dp[ind][target]!=-1)
    return dp[ind][target];
    int notPick=helper(coins,ind-1,target,dp);
    int pick=INT_MAX;
    if(coins[ind]<=target)
    {
         pick=1+helper(coins,ind,target-coins[ind],dp);
        // if(res!=-1)
        // pick=1+res;
    }
    return dp[ind][target]= min(pick,notPick);
}
    int coinChange(vector<int>& coins, int amount)
     {
        // vector<vector<int>>dp(coins.size(), vector<int>(amount+1,-1));
        // int res= helper(coins,coins.size()-1,amount,dp);
        // if(res>=1e9)
        // return -1;
        // return res;

        //Tabulation Approach
        //Bottom Up Approach
        vector<vector<int>>dp(coins.size(), vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0)
            dp[0][i]=i/coins[0];
            else
            dp[0][i]=1e9;
        }
        for(int ind=1;ind<coins.size();ind++)
        {
            for(int t=0;t<=amount;t++)
            {
                int notPick=0+dp[ind-1][t];
                int pick=INT_MAX;
                if(coins[ind]<=t)
                {
                    pick=1+dp[ind][t-coins[ind]];
                }
                dp[ind][t]=min(notPick,pick);
            }
        }
        int res= dp[coins.size()-1][amount];
        if(res>=1e9)
        return -1;
        return res;
         
        //Space Optimization 
        vector<int>prev(amount+1,0);
        vector<int>curr(amount+1,0);
          for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0)
            {
                prev[i]=i/coins[0];
            }
            else
            {
                prev[i]=1e9;
            }
        }

        for(int ind=1;ind<coins.size();ind++)
        {
            for(int target=0;target<=amount;target++)
            {
                int notPick=0+prev[target];
                int pick=INT_MAX;
                if(coins[ind]<=target)
                {
                    pick=1+curr[target-coins[ind]];
                }
                curr[target]=min(pick,notPick);
            }
            prev=curr;
        }
        int res= prev[amount];
        if(res>=1e9)
        return -1;
        return res;

    }
};
    }

};
