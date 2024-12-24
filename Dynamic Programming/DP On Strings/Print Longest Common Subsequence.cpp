int helper(string& s1, string& s2, int i, int j)
{
	if(i==0 || j==0)
	return 0;

	if(s1[i-1]==s2[j-1])
	return 1+helper(s1,s2,i-1,j-1);

	else
	return 0+max(helper(s1,s2,i-1,j),helper(s1,s2,i,j-1));
}
string findLCS(int n, int m,string &s1, string &s2)
{
	// Write your code here.	
	// return helper(s1,s2,n,m);

	vector<vector<int>>dp(n+1, vector<int>(m+1,0));
	for(int j=0;j<=s2.length();j++)
	{
		dp[0][j]=0;
	}
	for(int i=0;i<=s1.length();i++)
	{
		dp[i][0]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s1[i-1]==s2[j-1])
			dp[i][j]=1+dp[i-1][j-1];
			else
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	
	int i=n;
	int j=m;
	string str;
	while(i>0 && j>0)
	{
		if(s1[i-1]==s2[j-1])
		{
			str.push_back(s1[i-1]);
			i--;
			j--;
		}
		else if(dp[i-1][j]>dp[i][j-1])
		{
			i--;
		}
		else 
		{
			j--;
		}
	}
	reverse(str.begin(),str.end());
	return str;
	// cout<<dp[n][m];
	// return "Jolly";
}
