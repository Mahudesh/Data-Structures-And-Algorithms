#include <bits/stdc++.h> 
string encodeBase58(int N) 
{
	// Write your code here
	string str="123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";
	string ans="";
	if(N==0)
	return "1";
	while(N>0)
	{
		int quotient=N/58;
		int remainder=N%58;
		ans.push_back(str[remainder]);
		N=quotient;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

