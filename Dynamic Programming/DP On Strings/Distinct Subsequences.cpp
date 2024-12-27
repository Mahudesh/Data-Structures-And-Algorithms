class Solution {
public:
int helper(string& s1, string& s2, int i, int j, vector<vector<int>>& dp)
{
    //Once I Got Negative Index Which Means That Entire s2 Is Matched In s1
    if(j==0)
    return 1;
    if(i==0)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    if(s1[i-1]==s2[j-1])
    {
        //If Both Characters Matches Then It Could Be A Part Of Possible Subsequence 
        //So Move Both Indices From s1 And s2
        //If I Decide I Dont Want The Current Match
        //If I Want Another Letter Match For This Current Character In s2
        //Because Then Only I Can Find All The Possible Subsequences Of s2 in s1
        //I Can Move Only The Index Of i From s1
        return dp[i][j]=helper(s1,s2,i-1,j-1,dp)+helper(s1,s2,i-1,j,dp);
    }
    else
    {
        //If It Does Not Match Then For Sure 100% I Need To Move In s1
        //It Means Search For The Character Which Is Matching With s2 Character Only
        return dp[i][j]=helper(s1,s2,i-1,j,dp);
    }
}
    int numDistinct(string s, string t)
     {
        int n=s.length();
        int m=t.length();
        //Memoization
        // vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
        // return helper(s,t,n,m,dp);

        //Tabulation Approach
        //Bottom Up Approach
        //Base Case
        vector<vector<double>>dp(n+1, vector<double>(m+1,0));
        for(int i=0;i<=n;i++)
        dp[i][0]=1;

        //Start j From 1 Because I Cannot Overwrite Base Case Value Of j==0 In Prev Loop
        for(int j=1;j<=m;j++)
        dp[0][j]=0;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return (int)dp[n][m];

        //Space Optimization
        vector<double>prev(m+1,0);
        vector<double>curr(m+1,0);

        // for(int i=0;i<=n;i++)
        prev[0]=1;
        curr[0]=1; 

        //Start j From 1 Because I Cannot Overwrite Base Case Value Of j==0 In Prev Loop
        // for(int j=1;j<=m;j++)
        // prev[j]=0;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    curr[j]=prev[j-1]+prev[j];
                }
                else
                {
                    curr[j]=prev[j];
                }
            }
            prev=curr;
        }
        return (int)prev[m];

    }
};
