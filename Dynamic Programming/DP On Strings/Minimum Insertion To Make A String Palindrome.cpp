class Solution {
public:
    int minInsertions(string s1) 
    {
        //Always Keep The Longest Palindromic Subsequence String In Intact
        //And Replace In Reverse All Unmatched Characters Except LPS
        //So str.length()-LPS
        int len1=s1.length();
        string s2;
        for(int i=s1.length()-1;i>=0;i--)
        {
            s2.push_back(s1[i]);
        }
        int len2=s2.length();

        // vector<vector<int>>dp(len1+1, vector<int>(len2+1,0));

        // for(int j=0;j<=len2;j++)
        // dp[0][j]=0;

        // for(int i=0;i<=len1;i++)
        // dp[i][0];

        // for(int i=1;i<=len1;i++)
        // {
        //     for(int j=1;j<=len2;j++)
        //     {
        //         if(s1[i-1]==s2[j-1])
        //         {
        //             dp[i][j]=1+dp[i-1][j-1];
        //         }
        //         else
        //         {
        //             dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        //         }
        //     }
        // }

        //Space Optimized Approach
        vector<int>prev(len2+1,0);
        vector<int>curr(len2+1,0);
         for(int j=0;j<=len2;j++)
        prev[j]=0;

        for(int i=1;i<=len1;i++)
        {
            for(int j=1;j<=len2;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    curr[j]=1+prev[j-1];
                }
                else
                {
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        int ans=s1.length()-prev[len2];
        return ans;
    }
};
