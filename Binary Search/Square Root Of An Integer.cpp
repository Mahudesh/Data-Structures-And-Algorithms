#include <bits/stdc++.h> 
int helper(int ele, int n)
{
	if((long long)ele*ele <=n)
	return 1;
	else if((long long)ele*ele > n)
	return 0;
	return -1;
}
int squareRoot(int a)
{
	// Write your code here.
	int low=1;
	int high=a;
	int ans=0;
	while(low<=high)
	{
		int mid=(low+high)/2;
		int ch=helper(mid,a);
		if(ch==1)
		{
			ans=mid;
			low=mid+1;
		}
		else if(ch==0)
		{
			high=mid-1;
		}
	}
	return ans;
}
