class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int len1=word1.length();
        int len2=word2.length();

        vector<vector<int>>dp(len1+1,vector<int>(len2+1,0));

        for(int j=0;j<=len2;j++)
        dp[0][j]=0;

        for(int i=0;i<=len1;i++)
        dp[i][0]=0;

        for(int i=1;i<=len1;i++)
        {
            for(int j=1;j<=len2;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        //Space Optimized Version
        // vector<int>prev(len2+1,0);
        // vector<int>curr(len2+1,0);

        
        // for(int j=0;j<=len2;j++)
        // prev[j]=0;

        // for(int i=1;i<=len1;i++)
        // {
        //     for(int j=1;j<=len2;j++)
        //     {
        //         if(word1[i-1]==word2[j-1])
        //         {
        //             curr[j]=1+prev[j-1];
        //         }
        //         else
        //         {
        //             curr[j]=0+max(prev[j],curr[j-1]);
        //         }
        //     }
        //     prev=curr;
        // }




        int lcs=dp[len1][len2];
        //I Cannot Touch The Strings That AreCommon To Both The Strings
        //Deletions = len1 - LCS
        //Insertions = len2 - LCS
        //Total = len1 + len2 - (2*LCS)
        return len1+len2-(2*lcs);
        
    }
};
