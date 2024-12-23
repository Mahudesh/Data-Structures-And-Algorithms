int helper(vector<int>&prices, int ind, int maxRodLength, vector<vector<int>>& dp)
{
	if(ind==0)
	{
		return (prices[ind])*maxRodLength;
	}
	if(dp[ind][maxRodLength]!=-1)
	return dp[ind][maxRodLength];
	int notPick=0+helper(prices,ind-1,maxRodLength,dp);
	int pick=INT_MIN;
	int smallRodLength=ind+1;
	if(smallRodLength<=maxRodLength)
	{
		pick=prices[ind]+helper(prices,ind,maxRodLength-smallRodLength,dp);
	}
	return dp[ind][maxRodLength]=max(pick,notPick);
}
int cutRod(vector<int> &price, int N)
{
	// Write your code here.
	//Collect Rods Smaller Lengths And Try To Make It To Bigger Length N
	//Sum Up All Smaller Rod Length To N Rod Length With Finding Maximum Prices Out Of It
	// vector<vector<int>>dp(N, vector<int>(N+1,-1));
	// return helper(price,price.size()-1,N,dp);

	//Tabulation Approach
	//Bottom Up Approach
	// vector<vector<int>>dp(N, vector<int>(N+1,0));
	// for(int i=0;i<=N;i++)
	// {
	// 	dp[0][i]=price[0]*i;
	// }
	// for(int ind=1;ind<price.size();ind++)
	// {
	// 	for(int maxRod=0;maxRod<=N;maxRod++)
	// 	{
	// 		int notPick=0+dp[ind-1][maxRod];
	// 		int pick=INT_MIN;
	// 		int smallRodLength=ind+1;
	// 		if(smallRodLength<=maxRod)
	// 		{
	// 			pick=price[ind]+dp[ind][maxRod-smallRodLength];
	// 		}
	// 		dp[ind][maxRod]=max(pick,notPick);
	// 	}
	// }
	// return dp[price.size()-1][N];

	//Space Optimization
	vector<int>prev(N+1,0);
	vector<int>curr(N+1,0);
	for(int i=0;i<=N;i++)
	{
		prev[i]=price[0]*i;
	}
	for(int ind=1;ind<price.size();ind++)
	{
		for(int maxRod=0;maxRod<=N;maxRod++)
		{
			int notPick=0+prev[maxRod];
			int pick=INT_MIN;
			int smallRodLength=ind+1;
			if(smallRodLength<=maxRod)
			{
				pick=price[ind]+curr[maxRod-smallRodLength];
			}
			curr[maxRod]=max(pick,notPick);
		}
		prev=curr;
	}
	return prev[N];


}
