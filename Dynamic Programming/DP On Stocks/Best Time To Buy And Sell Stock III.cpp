class Solution {
public:
int helper(vector<int>& prices, int ind, int buy, int maxTransactions, vector<vector<vector<int>>>& dp)
{
    if(maxTransactions==0)
    return 0;
    if(ind==prices.size())
    return 0;
    int profit=0;
    if(dp[ind][buy][maxTransactions]!=-1)
    return dp[ind][buy][maxTransactions];
    
        if(buy==1)
        {
            profit= max(-prices[ind]+helper(prices,ind+1,0,maxTransactions,dp),
                    0+helper(prices,ind+1,1,maxTransactions,dp));
        }
        else
        {
            profit=max(prices[ind]+helper(prices,ind+1,1,maxTransactions-1,dp),0+helper(prices,ind+1,0,maxTransactions,dp));
        }
        
    
    return dp[ind][buy][maxTransactions]=profit;
}
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        // vector<vector<int>>dp(n+1, vector<int>(2,-1));
        //3 Changing Parameters
        //Hence I Would Opt For 3D DP
        // 1st Parameter ind from 0 to n
        //2nd Parameter buy from 0 to 1
        //3rd Parameter maxTransactions from 0 to maxTransactions
        // vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3,-1)));
        // return helper(prices,0,1,2,dp);

        //Tabulation Approach
        //Bottom Up Approach
        // vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));

        // // for(int ind=0;ind<n;ind++)
        // // {
        // //     dp[ind][0][0]=0;
        // //     dp[ind][1][0]=0;
        // // }
        // for(int ind=n-1;ind>=0;ind--)
        // {
        //     for(int buy=0;buy<=1;buy++)
        //     {
        //         for(int maxt=1;maxt<=2;maxt++)
        //         {
        //             int profit=0;
        //             if(buy==1)
        //             {
        //                 profit=max(-prices[ind]+dp[ind+1][0][maxt],0+dp[ind+1][1][maxt]);
        //             }
        //             else
        //             {
        //                 profit=max(prices[ind]+dp[ind+1][1][maxt-1],0+dp[ind+1][0][maxt]);
        //             }
        //             dp[ind][buy][maxt]=profit;
        //         }
        //     }
        // }
        // return dp[0][1][2];

        //Space Optimization
        //Optimize Only ind+1 Part By Precalculating It
        //Other Parameters Will Be As Constant As Constant
        //Create A DP Array Of 2X3 For Space Optimization
        vector<vector<int>>ahead(2, vector<int>(3,0));
        vector<vector<int>>curr(2, vector<int>(3,0));

        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int maxt=1;maxt<=2;maxt++)
                {
                    int profit=0;
                    if(buy==1)
                    {
                        profit=max(-prices[ind]+ahead[0][maxt],0+ahead[1][maxt]);
                    }
                    else
                    {
                        profit=max(prices[ind]+ahead[1][maxt-1],0+ahead[0][maxt]);
                    }
                    curr[buy][maxt]=profit;
                }
            }
            ahead=curr;
        }
        return ahead[1][2];


    }
};
