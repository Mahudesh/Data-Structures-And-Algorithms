class Solution {
public:
int helper(vector<int>& prices, int ind,int buy, int maxTransactions, vector<vector<vector<int>>>& dp)
{
    if(maxTransactions==0)
    return 0;
    if(ind==prices.size())
    return 0;
    int profit=0;
    if(dp[ind][buy][maxTransactions] != -1)
    return dp[ind][buy][maxTransactions];
    if(buy==1)
    {
        profit=max(-prices[ind]+helper(prices,ind+1,0,maxTransactions,dp) , 0+helper(prices,ind+1,1,maxTransactions,dp));
    }
    else
    {
        profit=max(prices[ind]+helper(prices,ind+1,1,maxTransactions-1,dp) , 0+helper(prices,ind+1,0,maxTransactions,dp));
    }
    return dp[ind][buy][maxTransactions]=profit;
}
    int maxProfit(int k, vector<int>& prices)
     {
        int n=prices.size();
        // vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(k+1,-1)));
        // return helper(prices,0,1,k,dp);

    //     vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(k+1,0)));

    //     for(int ind=n-1;ind>=0;ind--)
    //     {
    //         for(int buy=0;buy<=1;buy++)
    //         {
    //             for(int maxTr=1;maxTr<=k;maxTr++)
    //             {
    //                 int profit=0;
    //                 if(buy==1)
    //                 {
    //                     profit=max(-prices[ind]+dp[ind+1][0][maxTr] , 0+dp[ind+1][1][maxTr]);
    //                 }
    //                 else
    //                 {
    //                     profit=max(prices[ind]+dp[ind+1][1][maxTr-1] , 0+dp[ind+1][0][maxTr]);
    //                 }
    //                 dp[ind][buy][maxTr]=profit;
    //             }
    //         }
    //     }
    //    return  dp[0][1][k];

       //Space Optimization
       //2 2-D Vectors

        vector<vector<int>>ahead(2, vector<int>(k+1,0));
        vector<vector<int>>curr(2, vector<int>(k+1,0));
       for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int maxTr=1;maxTr<=k;maxTr++)
                {
                    int profit=0;
                    if(buy==1)
                    {
                        profit=max(-prices[ind]+ahead[0][maxTr] , 0+ahead[1][maxTr]);
                    }
                    else
                    {
                        profit=max(prices[ind]+ahead[1][maxTr-1] , 0+ahead[0][maxTr]);
                    }
                    curr[buy][maxTr]=profit;
                }
            }
            ahead=curr;
        }
       return  ahead[1][k];


    }
};
