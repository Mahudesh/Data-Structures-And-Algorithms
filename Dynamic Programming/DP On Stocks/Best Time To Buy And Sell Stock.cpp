class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int profit=0;
        // mini=INT_MAX;
        int mini=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            // mini=min(mini,prices[i]);
            int t=prices[i]-mini;
            if(t>=0)
            profit=max(profit,t);
             mini=min(mini,prices[i]);
        }
        return profit;
    }
};
