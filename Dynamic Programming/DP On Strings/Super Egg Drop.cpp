class Solution {
public:
int helper(int eggs, int n, vector<vector<int>>& dp)
{
    if(n<=1)
    return n;
    if(eggs==1)
    return n;
    if(dp[n][eggs]!=-1)
    return dp[n][eggs];
    int mini=1e9;
    // for(int currFloor=1;currFloor<=n;currFloor++)
    // {
    //    mini=min(mini,max(helper(eggs,n-currFloor,dp),helper(eggs-1,currFloor-1,dp))+1);
    // }

    int low=1;
    int high=n;
    while(low<=high)
    {
        int midcurrFloor=(low+high)/2;
        int notBroken = helper(eggs,n-midcurrFloor,dp);
        int broken = helper(eggs-1,midcurrFloor-1,dp);

        mini=min(mini,max(broken,notBroken)+1);

        if(broken<notBroken)
        {
            // high=mid-1;
            low=midcurrFloor+1;
        }
        else
        {
            high=midcurrFloor-1;
        }
    }
   return dp[n][eggs]=mini;
}
    int superEggDrop(int k, int n)
     {
        //Recursion + Memoization + Binary Search Approach
        vector<vector<int>>dp(n+1, vector<int>(k+1,-1));
        return helper(k,n,dp);

        //Tabulation Approach
        //Bottom Up Approach

        // vector<vector<int>>dp(n+1, vector<int>(k+1,0));

        // //If Floor==1 The Possible Eggs Could Be from 1 To K
        // for(int eg=1;eg<=k;eg++)
        // {
        //     dp[1][eg]=1;
        // }

        // //If Eggs==1 The Possible Floors Can Be From 1 To N
        // for(int fl=1;fl<=n;fl++)
        // {
        //     dp[fl][1]=fl;
        // }

        // for(int fl=2;fl<=n;fl++)
        // {
        //     for(int egg=2;egg<=k;egg++)
        //     {
        //         int mini=1e9;
        //         for(int currFloor=1;currFloor<=fl;currFloor++)
        //         {
        //             mini=min(mini,max(dp[fl-currFloor][egg], dp[currFloor-1][egg-1])+1);
        //         }
        //         dp[fl][egg]=mini;
        //     }
        // }
        // return dp[n][k];
    }
};
