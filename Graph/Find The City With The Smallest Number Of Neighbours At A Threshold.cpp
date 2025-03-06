#include <bits/stdc++.h> 
int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) 
{
	// Write your code here
	vector<vector<int>>cost(n, vector<int>(n,1e9));
	for(int i=0;i<n;i++)
	cost[i][i]=0;

	for(int i=0;i<edges.size();i++)
	{
		int u=edges[i][0];
		int v=edges[i][1];
		int wt=edges[i][2];
		cost[u][v]=wt;
		cost[v][u]=wt;
	}
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
			}
		}
	}
	int cityInd=-1;
	int cnt=0;
	int cityMax=INT_MAX;
	for(int i=0;i<n;i++)
	{
		cnt=0;
		for(int j=0;j<n;j++)
		{
			if(cost[i][j]<=distanceThreshold)
			{
				// cityInd=i;
				cnt++;
			}
		}
		if(cnt<=cityMax)
		{
			// cnt=city
			cityMax=cnt;
			cityInd=i;
		}
	}
	return cityInd;
}
