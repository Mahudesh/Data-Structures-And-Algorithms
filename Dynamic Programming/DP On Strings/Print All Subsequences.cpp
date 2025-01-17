class Solution {
  public:

void findAllLCS(vector<vector<int>>& dp,set<string>& ans,string& s1, string& s2, int i, int j, string& temp)
{
    if(i==0 || j==0)
    {
        string res=temp;
        reverse(res.begin(),res.end());
        ans.insert(res);
        return;
    }
    
    if(s1[i-1]==s2[j-1])
    {
        temp.push_back(s1[i-1]);
        
        findAllLCS(dp,ans,s1,s2,i-1,j-1,temp);
        
        temp.pop_back();
    }
    else
    {
        if(dp[i-1][j]==dp[i][j])
        {
            findAllLCS(dp,ans,s1,s2,i-1,j,temp);
        }
        if(dp[i][j-1]==dp[i][j])
        {
            findAllLCS(dp,ans,s1,s2,i,j-1,temp);
        }
    }
}
    vector<string> all_longest_common_subsequences(string s, string t) 
    {
        // Code here
        int n=s.length();
        int m=t.length();
        // helper(s,t,n,m);
        vector<vector<int>>dp(n+1, vector<int>(m+1,0));
        
        for(int j=0;j<=m;j++)
        {
            dp[0][j]=0;
        }
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        set<string>st;
        string temp;
        findAllLCS(dp,st,s,t,n,m,temp);
        vector<string>result(st.begin(),st.end());
        return result;
        
    }
};
