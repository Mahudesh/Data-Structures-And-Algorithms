#include <bits/stdc++.h> 
int ctof(int f)
{
	return (5.0/9.0)*(f-32);
}
vector<vector<int>> fahrenheitToCelsius(int s, int e, int w)
{
	//type your code here
	int m=0;
	vector<vector<int>>ans;
	for(int f=s;f<=e;f=f+w)
	{
		m=ctof(f);
		ans.push_back({f,m});
	}
	return ans;
}
