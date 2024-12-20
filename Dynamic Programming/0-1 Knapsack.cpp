#include<algorithm>
#include<climits>
int helper(vector<int>& values, vector<int>& weights,int ind, int n, int maxWeight,vector<vector<int>>& dp)
{
	if(ind==0)
	{
		if(weights[ind]<=maxWeight)
		{
			return values[ind];
		}
		else
		{
			return 0;
		}

	}
	if(dp[ind][maxWeight]!=-1)
	return dp[ind][maxWeight];
	int notTake=0+helper(values,weights,ind-1,n,maxWeight,dp);
	int take=INT_MIN;
	if(weights[ind]<=maxWeight)
	{
		take=values[ind]+helper(values,weights,ind-1,n,maxWeight-weights[ind],dp);
	}
	return dp[ind][maxWeight]=max(notTake,take);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// vector<vector<int>>dp(n, vector<int>(w+1,-1));
	// return helper(values,weights,n-1,n,w,dp);
	//Tabulation Approach
	//Bottom Up Approach
	// vector<vector<int>>dp(n, vector<int>(w+1,0));
	//At Index 0 If Max Bag Weight Is 5
	//Then If I Pass Bag Weight Of 4 It Will Return 0
	//If I Pass Bag Weight Of 3 It Will Return 0
	//But Once If I Pass A Bag Weight Of 6 Which Is More Than Max Capacity
	//Then The Value Will Be Taken
	// for(int i=weights[0];i<=w;i++)
	// {
	// 	dp[0][i]=values[0];
	// }
	// for(int ind=1;ind<n;ind++)
	// {
	// 	for(int wt=0;wt<=w;wt++)
	// 	{
	// 		int notTake=0+dp[ind-1][wt];
	// 		int take=INT_MIN;
	// 		if(weights[ind]<=wt)
	// 		{
	// 			take=values[ind]+dp[ind-1][wt-weights[ind]];
	// 		}
	// 		dp[ind][wt]=max(notTake,take);
	// 	}
	// }
	// return dp[n-1][w];

	//Space Optimization
	// vector<int>prev(w+1,0);
	// vector<int>curr(w+1,0);
	// for(int i=weights[0];i<=w;i++)
	// {
	// 	prev[i]=values[0];
	// }
	// for(int ind=1;ind<n;ind++)
	// {
	// 	for(int wt=0;wt<=w;wt++)
	// 	{
	// 		int notTake=0+prev[wt];
	// 		int take=INT_MIN;
	// 		if(weights[ind]<=wt)
	// 		{
	// 			take=values[ind]+prev[wt-weights[ind]];
	// 		}
	// 		curr[wt]=max(notTake,take);
	// 	}
	// 	prev=curr;
	// }
	// return prev[w];
	//Because Of The Property wt-weights[ind] It Requires Only Left Half Of Array Every Time
	//Hence If I Able To Store The Values At Prev Array In Reverse Order
	//Then For The Value Of wt-weights[ind] Can Be Obtained From Left Half Of Prev Array
	//So Store The Elements Of Weight From Backwards

	//Why Filling In 0 to w Not Works??
	//If I Filled For 2 Indices And If I Calculate The 3rd Index
	//Then It Will Search On Indices 0 - 2 Which  Is OverWritten Already
	//So It Should Depend Only On Prev Calculated Values

	
	//Space Optimization
	vector<int>prev(w+1,0);
	// vector<int>curr(w+1,0);
	for(int i=weights[0];i<=w;i++)
	{
		prev[i]=values[0];
	}
	for(int ind=1;ind<n;ind++)
	{
		for(int wt=w;wt>=0;wt--)
		{
			int notTake=0+prev[wt];
			int take=INT_MIN;
			if(weights[ind]<=wt)
			{
				take=values[ind]+prev[wt-weights[ind]];
			}
			prev[wt]=max(notTake,take);
		}
		// prev=curr;
	}
	return prev[w];

}
