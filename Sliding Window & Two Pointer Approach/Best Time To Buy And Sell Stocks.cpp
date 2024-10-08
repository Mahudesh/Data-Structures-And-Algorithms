class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int profit=0;
        int mini=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            profit=max(profit,prices[i]-mini);
            mini=min(mini,prices[i]);
        }
        return profit;
        // int profit=0;
        // for(int i=0;i<prices.size();i++)
        // {
        //     int price=prices[i];
        //     for(int j=i+1;j<prices.size();j++)
        //     {
        //         if(price<prices[j])
        //         {
        //             profit=max(profit,prices[j]-price);
        //         }
        //     }
        // }
        // return profit;
    }
};
