#include<stack>
int findHistogram(vector<int>&arr)
{
	int n=arr.size();
	vector<int>prevSmaller(n,0);
	vector<int>nextSmaller(n,n-1);
	stack<int>st;
	for(int i=0;i<n;i++)
	{
		while(!st.empty() && arr[st.top()]>=arr[i])
		{
			st.pop();
		}
		if(!st.empty())
		{
			prevSmaller[i]=st.top()+1;
		}
		st.push(i);
	}
	while(!st.empty())
	{
		st.pop();
	}
	for(int i=n-1;i>=0;i--)
	{
		while(!st.empty() && arr[st.top()]>=arr[i])
		{
			st.pop();
		}
		if(!st.empty())
		{
			nextSmaller[i]=st.top()-1;
		}
		st.push(i);
	}
	int area=0;
	for(int i=0;i<n;i++)
	{
		int width=nextSmaller[i]-prevSmaller[i]+1;
		int height=arr[i];
		area=max(area,width*height);
	}
	return area;

}
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m)
{
	// Write your code here.
	vector<vector<int>> prefixSum(n, vector<int>(m));
	for(int j=0;j<m;j++)
	{
		int sum=0;
		for(int i=0;i<n;i++)
		{
			sum+=mat[i][j];
			if(mat[i][j]==0)
			{
				sum=0;
			}
			prefixSum[i][j]=sum;
		}
	}
	int maxi=0;
	for(int i=0;i<prefixSum.size();i++)
	{
		maxi=max(maxi,findHistogram(prefixSum[i]));
	}
	return maxi;
}
