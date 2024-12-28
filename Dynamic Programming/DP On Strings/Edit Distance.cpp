class Solution {
public:
int helper(string&s1, string& s2, int i, int j, vector<vector<int>>& dp)
{
    //Base Case
    if(i==0)
    return j;
    if(j==0)
    return i;
    if(dp[i][j]!=-1)
    return dp[i][j];
    if(s1[i-1]==s2[j-1])
    {
        return dp[i][j]=0+helper(s1,s2,i-1,j-1,dp);
    }
    else
    {
        return dp[i][j]=min(min(1+helper(s1,s2,i,j-1,dp),1+helper(s1,s2,i-1,j,dp)), 1+helper(s1,s2,i-1,j-1,dp));
    }
}
    int minDistance(string word1, string word2) 
    {
        int len1=word1.length();
        int len2=word2.length();
        // vector<vector<int>>dp(len1+1, vector<int>(len2+1,-1));
        // return helper(word1,word2,len1,len2,dp);

        //Tabulation Approach
        //Bottom Up Approach
        // vector<vector<int>>dp(len1+1,vector<int>(len2+1,0));

        // for(int j=0;j<=len2;j++)
        // {
        //     dp[0][j]=j;
        // }
        // for(int i=1;i<=len1;i++)
        // {
        //     dp[i][0]=i;
        // }

        // for(int i=1;i<=len1;i++)
        // {
        //     for(int j=1;j<=len2;j++)
        //     {
        //         if(word1[i-1]==word2[j-1])
        //         {
        //             dp[i][j]=0+dp[i-1][j-1];
        //         }
        //         else
        //         {
        //             dp[i][j]=min(min(1+dp[i][j-1],1+dp[i-1][j]),1+dp[i-1][j-1]);
        //         }
        //     }
        // }
        // return dp[len1][len2];

        //Space Optimized Approach
        vector<int>prev(len2+1,0);
        vector<int>curr(len2+1,0);

          for(int j=0;j<=len2;j++)
        {
            prev[j]=j;
        }
        // for(int i=1;i<=len1;i++)
        // {
        //     dp[i][0]=i;
        // }

        for(int i=1;i<=len1;i++)
        {
            curr[0]=i;
            for(int j=1;j<=len2;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    curr[j]=0+prev[j-1];
                }
                else
                {
                    curr[j]=min(min(1+curr[j-1],1+prev[j]),1+prev[j-1]);
                }
            }
            prev=curr;
        }
        return prev[len2];
    }
};
