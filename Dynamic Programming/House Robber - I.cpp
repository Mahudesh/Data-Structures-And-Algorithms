#include<climits>
int helper(int ind, vector<int>&houses, vector<int>&dp)
{
	if(ind==0)
	return houses[0];
	if(ind<0)
	return 0;
	if(dp[ind]!=-1)
	return dp[ind];
	int pick=houses[ind]+helper(ind-2,houses,dp);
	int leftOut=helper(ind-1,houses,dp);
	return dp[ind]=max(pick,leftOut);
}
int maxMoneyLooted(vector<int> &houses, int n)
{
	/*
		Write your code here.
		Don't write main().
	 	Don't take input, it is passed as function argument.
	 	Don't print output.
	 	Taking input and printing output is handled automatically.
	*/
	// vector<int>dp(n,-1);
	// return helper(houses.size()-1,houses,dp);
	//Tabulation Method

	// vector<int>dp(n,0);
	// dp[0]=houses[0];
	// for(int i=1;i<n;i++)
	// {
	// 	int pick=houses[i];
	// 	if(i>1)
	// 	pick=pick+dp[i-2];
	// 	int leftOut=dp[i-1];
	// 	dp[i]=max(pick,leftOut);
	// }
	// return dp[n-1];

	//Space Optimization
	//You Just Need The Last Two Previous Guy For Calculating Current i
	//So Keep Track Of Previous Last Two
	//Once i Moves The Second Previous Becomes Previous And Previous Will Becomes Current
	//Finally Answer Will Be Stored At Prev
	int prev=houses[0];
	int secPrev=0;
	int ans=0;
	for(int i=1;i<n;i++)
	{
		int pick=houses[i];
		if(i>1)
		pick+=secPrev;
		int leftOut=prev;
		ans=max(pick,leftOut);
		secPrev=prev;
		prev=ans;
	}
	return prev;
	
}
