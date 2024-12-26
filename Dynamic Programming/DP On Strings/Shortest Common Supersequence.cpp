#include <bits/stdc++.h> 
string shortestSupersequence(string a, string b)
{
	// Write your code here.
	//Find LCS Of Two Strings First
	int len1=a.length();
	int len2=b.length();
	vector<vector<int>>dp(len1+1, vector<int>(len2+1,0));
	for(int i=0;i<=len1;i++)
	{
		for(int j=0;j<=len2;j++)
		{
			if(i==0 || j==0)
			dp[i][j]=0;
			else if(a[i-1]==b[j-1])
			{
				dp[i][j]=1+dp[i-1][j-1];
			}
			else
			{
				dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	//For Common Characters In Both The Strings I Can Take It Only Once
	//For Other Characters I Can Take Both From The String Whereas Maintaining My Order
	string ans="";
	int i=len1;
	int j=len2;
	while(i>0 && j>0)
	{
		if(a[i-1]==b[j-1])
		{
			ans.push_back(a[i-1]);
			i--;
			j--;
		}
		else if(dp[i-1][j]>dp[i][j-1])
		{
			ans.push_back(a[i-1]);
			i--;
		}
		else
		{
			ans.push_back(b[j-1]);
			j--;
		}
	
	}

	//At The End There Can Be Any One Of The String Can Be Left
	while(i>0)
	{
		ans.push_back(a[i-1]);
		i--;
	}
	while(j>0)
	{
		ans.push_back(b[j-1]);
		j--;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
