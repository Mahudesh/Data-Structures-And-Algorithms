#include<climits>
int helper(vector<int>& profit, vector<int>& weight,int ind, int maxWeight, vector<vector<int>>& dp)
{
    if(ind==0)
    {
        //U Can Take As Much Amount Of Points From Bag At Index = 0
        //Since It Has Infinite Supply
        //If maxWeight=12 And Index = 0 Contains Weight[0] = 5
        //Then OfCourse We Can Take 12/5 = 2 Times Of Points From That Bag
         if(maxWeight/weight[0]>0)
        {
            int times=maxWeight/weight[0];
            return times*profit[0];
        }
        return 0;
    }
    if(dp[ind][maxWeight]!=-1)
    return dp[ind][maxWeight];
    int notPick=0+helper(profit,weight,ind-1,maxWeight,dp);
    int pick=INT_MIN;
    if(weight[ind]<=maxWeight)
    {
        pick=profit[ind]+helper(profit,weight,ind,maxWeight-weight[ind],dp);
    }
    return dp[ind][maxWeight]=max(notPick,pick);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    // vector<vector<int>>dp(n, vector<int>(w+1,-1));
    // return helper(profit,weight,profit.size()-1,w,dp);

    //Tabulation Approach
    //Bottom Up Approach
    // vector<vector<int>>dp(n, vector<int>(w+1,0));
    // for(int i=0;i<=w;i++)
    // {
    //     dp[0][i]=((i)/weight[0])*profit[0];
    // }

    // for(int ind=1;ind<n;ind++)
    // {
    //     for(int wt=0;wt<=w;wt++)
    //     {
    //         int notPick=dp[ind-1][wt];
    //         int pick=INT_MIN;
    //         if(weight[ind]<=wt)
    //         pick=profit[ind]+dp[ind][wt-weight[ind]];
    //         dp[ind][wt]=max(notPick,pick);
    //     }
    // }
    // return dp[n-1][w];

    //Space Optimization
    vector<int>prev(w+1,0);
    vector<int>curr(w+1,0);
    //For Index = 0 The MaxWeight Ranges From 0 To MaxWeight With The Condition
    //Condition Will Be Like How Many Times It Can Take The Points From Bags[0]
    for(int i=0;i<=w;i++)
    {
        prev[i]=((i)/weight[0])*profit[0];
    }

    for(int ind=1;ind<n;ind++)
    {
        for(int wt=0;wt<=w;wt++)
        {
            int notPick=prev[wt];
            int pick=INT_MIN;
            if(weight[ind]<=wt)
            pick=profit[ind]+curr[wt-weight[ind]];
            curr[wt]=max(notPick,pick);
        }
        prev=curr;
    }
    return prev[w];

}
