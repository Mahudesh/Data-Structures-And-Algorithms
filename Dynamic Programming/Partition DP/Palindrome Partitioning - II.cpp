class Solution {
public:
bool isPalindrome(int i, int j, string& str)
{
    while(i<=j)
    {
        if(str[i]!=str[j])
        return false;
        i++;
        j--;
    }
    return true;
}
int helper(int i, int n,string& str, vector<int>& dp)
{
    if(i==n)
    return 0;

    if(dp[i]!=-1)
    return dp[i];

    int mini=1e9;
    for(int j=i;j<=n-1;j++)
    {
        if(isPalindrome(i,j,str))
        {
            int cnt = 1+helper(j+1,n,str,dp);
            mini=min(mini,cnt);
        }
    }
    return dp[i]=mini;
}
    int minCut(string s) 
    {
        //Front Partition Technique 
        //Trying Out All Partition Technique If A String Is Only Palindrome From i=0 To s.length()-1
        vector<int>dp(s.length(),-1);
        return helper(0,s.length(),s,dp)-1;
    }
};
