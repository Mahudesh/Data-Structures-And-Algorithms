#include <bits/stdc++.h> 
int kadanesAlgorithm(vector <int>& arr)
{
	int sum=0;
	int maxSum=INT_MIN;
	for(int i=0;i<arr.size();i++)
	{
		sum+=arr[i];
		maxSum=max(maxSum,sum);
		if(sum<0)
		sum=0;
	}
	return maxSum;
}
int maxSumRectangle(vector<vector<int>>& arr, int n, int m)
{
	// write your code here
	int maxSum=INT_MIN;
	for(int topRow=0;topRow<n;topRow++)
	{
		vector<int>temp(m,0);
		for(int r=topRow;r<n;r++)
		{
			for(int c=0;c<m;c++)
			{
				temp[c]=temp[c]+arr[r][c];
			}
				int sum=kadanesAlgorithm(temp);
				if(maxSum<sum)
				maxSum=sum;
		}
	}
	return maxSum;
}
