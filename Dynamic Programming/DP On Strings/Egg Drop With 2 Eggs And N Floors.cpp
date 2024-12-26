class Solution {
public:
int helper(int flor, int eggs, vector<vector<int>>& dp)
{
    if(flor<=1)
    return flor;
    if(eggs==1)
    return flor;
    if(dp[flor][eggs]!=-1)
    return dp[flor][eggs];
    int mini=1e9;
    for(int i=1;i<=flor;i++)
    {
        int f = max(helper(flor-i,eggs,dp),helper(i-1,eggs-1,dp))+1;
        mini=min(mini,f);
    }
    return dp[flor][eggs]=mini;
}
    int twoEggDrop(int n)
     {
        // vector<vector<int>>dp(n+1, vector<int>(3,-1));
        // return helper(n,2,dp);

        //Tabulation Approach
        //Bottom Up Appproach
        //Keep n+1 Floors Since We Are Counting From 1st Floor To nth Floor
        //Keep 3 Columns Since I Have Only 1egg Or 2 Eggs 0 Eggs I Cannot Have
        vector<vector<int>>dp(n+1, vector<int>(3,0));
        int eggs=2;
        for(int i=1;i<=eggs;i++)
        {
            dp[1][i]=1;
        }
        for(int fl=1;fl<=n;fl++)
        {
            dp[fl][1]=fl;
        }

        for(int fl=2;fl<=n;fl++)
        {
            for(int e=2;e<=eggs;e++)
            {
                int mini=INT_MAX;
                for(int i=1;i<=fl;i++)
                {
                    int breakk=dp[i-1][e-1];
                    int notBreak=dp[fl-i][e];
                    mini=min(mini,max(breakk,notBreak)+1);
                    dp[fl][e]=mini;
                }
            }
        }
        return dp[n][eggs];


    }
};
