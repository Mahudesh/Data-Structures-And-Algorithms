class Solution {
public:
int helper(vector<int>& prices, int ind ,int buy, int fee, vector<vector<int>>& dp)
{
    if(ind==prices.size())
    return 0;
    if(dp[ind][buy]!=-1)
    return dp[ind][buy];
    int profit=0;
    if(buy==1)
    {
        profit=max(-prices[ind]+helper(prices,ind+1,0,fee,dp),0+helper(prices,ind+1,1,fee,dp));
    }
    else
    {
        profit=max((prices[ind]-fee)+helper(prices,ind+1,1,fee,dp),0+helper(prices,ind+1,0,fee,dp));
    }
    return dp[ind][buy]=profit;
}
    int maxProfit(vector<int>& prices, int fee)
     {
        int n=prices.size();
        // vector<vector<int>>dp(n+1, vector<int>(2,-1));
        // return helper(prices,0,1,fee,dp);

        //Tabulation Approach
        //Bottom Up Approach

        // vector<vector<int>>dp(n+1, vector<int>(2,0));
        // for(int i=0;i<=1;i++)
        // {
        //     dp[n][i]=0;
        // }
        // for(int ind=n-1;ind>=0;ind--)
        // {
        //     for(int buy=0;buy<=1;buy++)
        //     {
        //         int profit=0;
        //         if(buy==1)
        //         {
        //             profit=max(-prices[ind]+dp[ind+1][0], 0+dp[ind+1][1]);
        //         }
        //         else
        //         {
        //             profit=max(prices[ind]-fee + dp[ind+1][1], 0+dp[ind+1][0]);
        //         }
        //         dp[ind][buy]=profit;
        //     }
        // }
        // return dp[0][1];

        //Space Optimization Approach

        vector<int>ahead(2,0);
        vector<int>curr(2,0);

        //  vector<vector<int>>dp(n+1, vector<int>(2,0));
        // for(int i=0;i<=1;i++)
        // {
        //     dp[n][i]=0;
        // }
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit=0;
                if(buy==1)
                {
                    profit=max(-prices[ind]+ahead[0], 0+ahead[1]);
                }
                else
                {
                    profit=max(prices[ind]-fee + ahead[1], 0+ahead[0]);
                }
                curr[buy]=profit;
            }
            ahead=curr;
        }
        return ahead[1];
        
    }
};
