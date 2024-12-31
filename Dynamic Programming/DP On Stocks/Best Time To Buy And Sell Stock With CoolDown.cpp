class Solution {
public:
int helper(vector<int>& prices, int ind, int buy, vector<vector<int>>& dp)
{
    if(ind>=prices.size())
    return 0;
    if(dp[ind][buy]!=-1)
    return dp[ind][buy];
    int profit=0;
    if(buy==1)
    {
        profit=max(-prices[ind]+helper(prices,ind+1,0,dp) , 0+helper(prices,ind+1,1,dp));
    }
    else
    {
        profit=max(prices[ind]+helper(prices,ind+2,1,dp) , 0+helper(prices,ind+1,0,dp));
    }
    return dp[ind][buy]=profit;
}
    int maxProfit(vector<int>& prices)
     {
        int n=prices.size();
        // vector<vector<int>>dp(n+1, vector<int>(2,-1));
        // return helper(prices,0,1,dp);

        vector<vector<int>>dp(n+2, vector<int>(2,0));
        for(int i=0;i<=1;i++)
        {
            dp[n][i]=0;
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit=0;
                if(buy==1)
                {
                    profit=max(-prices[i]+dp[i+1][0],0+dp[i+1][1]);
                }
                else
                {
                    // if(i==n-1)
                    // profit=dp[i+1][0];
                    // else
                    profit=max(prices[i]+dp[i+2][1],0+dp[i+1][0]);
                }
                dp[i][buy]=profit;
            }
        }
        
        return dp[0][1];

    }
};
