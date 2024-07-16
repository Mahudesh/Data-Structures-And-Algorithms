#include <bits/stdc++.h> 
string binaryPuzzle(int n)
{
	// Write your code here.
	string ans="";
	while(n>=1)
	{
		if(n%2==1)
		ans+='1';
		else
		ans+='0';
		n=n/2;
	}
	reverse(ans.begin(),ans.end());
	return ans;

}
