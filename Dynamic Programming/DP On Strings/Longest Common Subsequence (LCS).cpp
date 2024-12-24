class Solution {
public:
int findLCS(string& str1, string& str2, int i, int j, vector<vector<int>>& dp)
{
    if(i==0 || j==0)
    return 0;
    //If Character Matches Then I Found A Subsequence Of Length 1
    //So Return 1 + And Move Both The Indices
    if(dp[i][j]!=-1)
    return dp[i][j];
    if(str1[i-1]==str2[j-1])
    {
        return dp[i][j]=1+findLCS(str1,str2,i-1,j-1,dp);
    }
    else
    {
        //If Character Does Not Matches Then Try Out All Possible Moves
        //Either If I Move ind1 And Staying ind2 At Fixed I Can Get A Match
        //Or If I Move ind2 And Staying ind1 At Fixed I Can Get A Match
        //Return The Best Possible Result Out Of It
        return dp[i][j]=0+max(findLCS(str1,str2,i-1,j,dp),findLCS(str1,str2,i,j-1,dp));
    }
}
    int longestCommonSubsequence(string text1, string text2)
     {
        //Generate The Subsequences And Meanwhile Try To Do The Comparison
        //Since I Need Comparison Between Two Strings I Need Two Indices
        //ind1 -> text1 ind2 -> text2

        int n=text1.length();
        int m=text2.length();
        // //Memoization Approach
        // vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
        // return findLCS(text1,text2,n,m,dp);

        //Tabulation Approach
        //Since In Recursion I Can Get ind1 As -1 Or ind2 As -1
        //But In Array I Cant Handle Negative Indices
        //So Do A Technique Called Shifting Of Indices
        //Right Shift All The Indices By 1 And Treat Every i And j As i-1 And j-1
        //Resize The dp Array To n+1 And m+1
        //Hence If i==0 || j==0 I Can Say That I Reached Negative Index
        //It Means The String Is Empty
        //So I Can Return 0

        //Bottom Up Approach
        //Base Case
        // vector<vector<int>>dp(n+1, vector<int>(m+1,0));
        // for(int j=0;j<=text2.length();j++)
        // {
        //     dp[0][j]=0;
        // }
        // for(int i=0;i<=text1.length();i++)
        // {
        //     dp[i][0]=0;
        // }
        // for(int i=1;i<=text1.length();i++)
        // {
        //     for(int j=1;j<=text2.length();j++)
        //     {
        //         if(text1[i-1]==text2[j-1])
        //         dp[i][j]=1+dp[i-1][j-1];
        //         else
        //         {
        //             dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);
        //         }
        //     }
        // }
        // return dp[n][m];

        //Space Optimization Approach
        vector<int>prev(m+1,0);
        vector<int>curr(m+1,0);
         for(int j=0;j<=text2.length();j++)
        {
            prev[j]=0;
        }
        for(int i=1;i<=text1.length();i++)
        {
            for(int j=1;j<=text2.length();j++)
            {
                if(text1[i-1]==text2[j-1])
                curr[j]=1+prev[j-1];
                else
                {
                    curr[j]=0+max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        return prev[m];

    }
};
