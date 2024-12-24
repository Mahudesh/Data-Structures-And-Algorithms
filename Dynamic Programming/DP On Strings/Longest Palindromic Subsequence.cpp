class Solution {
public:
    int longestPalindromeSubseq(string s1) 
    {
        string s2;
        for(int i=s1.length()-1;i>=0;i--)
        {
            s2.push_back(s1[i]);
        }
        int n=s1.length();
        int m=s2.length();
        // vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
        // return findLPS(n,m,s1,s2,dp);

        // vector<vector<int>>dp(n+1, vector<int>(m+1,0));

        // for(int j=0;j<=m;j++)
        // {
        //     dp[0][j]=0;
        // }
        // for(int i=0;i<=n;i++)
        // {
        //     dp[i][0]=0;
        // }
        // for(int i=1;i<=n;i++)
        // {
        //     for(int j=1;j<=m;j++)
        //     {
        //         if(s1[i-1]==s2[j-1])
        //         dp[i][j]=1+dp[i-1][j-1];
        //         else
        //         dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);
        //     }
        // }
        // return dp[n][m];


    //      string ans;
    // int i=n;
    // int j=m;
    // while(i>0 && j>0)
    // {
    //     if(s1[i-1]==s2[j-1])
    //     {
    //       ans.push_back(s1[i-1]);
    //       i--;
    //       j--;
    //     }
    //     else if(dp[i-1][j]>dp[i][j-1])
    //     i--;
    //     else
    //     j--;
    // }
        //Space Optimized Approach
        vector<int>prev(m+1,0);
        vector<int>curr(m+1,0);
        
        for(int j=0;j<=m;j++)
        {
            prev[j]=0;
        }
   
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                curr[j]=1+prev[j-1];
                else
                curr[j]=0+max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return prev[m];

    }
};
