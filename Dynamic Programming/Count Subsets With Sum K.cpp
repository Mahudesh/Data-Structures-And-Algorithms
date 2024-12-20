int mod=1e9+7;
int helper(vector<int>& arr,int ind, int target, vector<vector<int>>& dp)
{

	 if(ind==0)
	 {
		//  return arr[0]==target;
		if(arr[0]==0 && target==0)
		return 2;

		if(target==0 || arr[0]==target)
		return 1;

		return 0;
	 }
	 if(dp[ind][target]!=-1)
	 return dp[ind][target];
	 int notPick=helper(arr,ind-1,target,dp);
	 int pick=0;
	 if(arr[ind]<=target)
	 {
		 pick=helper(arr,ind-1,target-arr[ind],dp);
	 }
	 return dp[ind][target]=(pick+notPick)%mod;
}
int findWays(vector<int>& arr, int k)
{
	int n=arr.size();
	vector<vector<int>>dp(n, vector<int>(k+1,-1));
	return helper(arr,n-1,k,dp);
}
