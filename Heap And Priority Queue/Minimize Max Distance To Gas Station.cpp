#include<bits/stdc++.h>
double minimiseMaxDistance(vector<int> &arr, int k)
{
	// Write your code here.	
	//Look For How Many Gaps Available
	// vector<int>placed(arr.size()-1,0);
	// for(int gas=1;gas<=k;gas++)
	// {
	// 	long double maxDiff=-1;
	// 	int maxIndex=-1;
	// 	for(int i=0;i<arr.size()-1;i++)
	// 	{
	// 		long double diff=arr[i+1]-arr[i];

	// 		long double sectionDiff = diff/(long double)(1+placed[i]);

	// 		if(maxDiff<sectionDiff)
	// 		{
	// 			maxDiff=sectionDiff;
	// 			maxIndex=i;
	// 		}
	// 	}
	// 	placed[maxIndex]++;
	// }
	// long double ans=0;
	// for(int i=0;i<arr.size()-1;i++)
	// {
	// 	long double diff = arr[i+1]-arr[i];
	// 	long double sectionDiff = diff/(long double)(placed[i]+1);
	// 	ans=max(ans,sectionDiff);
	// }
	// return ans;

	//Better Approach
	//Reducing The Complexity For Searching Greatest Different For Placing Each Gas Station

	priority_queue<pair<long double,int>>pq;
	vector<int>placed(arr.size()-1,0);

	for(int i=0;i<arr.size()-1;i++)
	{
		long double diff=arr[i+1]-arr[i];
		pq.push({diff,i});
	}

	for(int gas=1;gas<=k;gas++)
	{
		auto todo = pq.top();
		pq.pop();
		int ind = todo.second;
		long double diff = arr[ind+1]-arr[ind];

		placed[ind]++;

		long double sectionDiff = diff/(long double)(1+placed[ind]);
		pq.push({sectionDiff,ind});


	}

	return pq.top().first;

}
