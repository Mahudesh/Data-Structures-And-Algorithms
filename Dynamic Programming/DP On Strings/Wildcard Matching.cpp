class Solution {
public:
bool helper(string& s1, string& s2, int i, int j, vector<vector<int>>& dp)
{
    if(i==0 && j==0)
    return true;
    if(i==0 && j>0)
    return false;
    if( j==0 && i>0)
    {
        for(int k=1;k<=i;k++)
        {
            if(s1[k-1]!='*')
            return false;
        }
        return true;
    }

    if(dp[i][j]!=-1)
    return dp[i][j];
    if(s1[i-1]==s2[j-1] || s1[i-1]=='?')
    {
        return dp[i][j]=helper(s1,s2,i-1,j-1,dp);   
    }
 
     if(s1[i-1]=='*')
    {
        return dp[i][j]=helper(s1,s2,i-1,j,dp) || helper(s1,s2,i,j-1,dp);
    }
    
        return dp[i][j]=false;
    
    
}
    bool isMatch(string s2, string s1)
     {
        int len1=s1.length();
        int len2=s2.length();
        // vector<vector<int>>dp(len2+1, vector<int>(len1+1,-1));
        // swap(s2,s1);
        // return helper(p,s,len2,len1,dp);

        //Tabulation Approach
        //Bottom Up approach
        vector<vector<bool>>dp(len1+1, vector<bool>(len2+1,false));
        dp[0][0]=true;
        for(int j=1;j<=len2;j++)
        dp[0][j]=false;
        for(int i=1;i<=len1;i++)
        {
            bool flag=true;
            for(int k=1;k<=i;k++)
            {
                if(s1[k-1]!='*')
                {
                    flag=false;
                    break;
                }
            }
            dp[i][0]=flag;
        }
        for(int i=1;i<=len1;i++)
        {
            for(int j=1;j<=len2;j++)
            {
                if(s1[i-1]==s2[j-1] || s1[i-1]=='?')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(s1[i-1]=='*')
                {
                    dp[i][j]=dp[i][j-1]|dp[i-1][j];
                }
                else
                {
                    dp[i][j]=false;
                }
            }
        }
        return dp[len1][len2];

    }
};
