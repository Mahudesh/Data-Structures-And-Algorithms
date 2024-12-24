Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) 
    {
        // your code here
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1,0));
        for(int j=0;j<=m;j++)
        {
            dp[0][j]=0;
        }
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
        }
        int maxi=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    //If It Matches Check For Previosuly Any Consecutive Matches
                    //1+ For Current Character With If Any Previous Matches
                    dp[i][j]=1+dp[i-1][j-1];
                    maxi=max(maxi,dp[i][j]);
                }
                else
                {
                    //Since It Is Not Matching Then There Comes A Disrupt
                    //A Disturbance Or Non - Matched Character Arises
                    //Hence It Does Not Depend Upon Previous Result
                    //If Any Disrupt Occurs Then Make It As 0
                    dp[i][j]=0;
                }
            }
        }
        return maxi;
    }
