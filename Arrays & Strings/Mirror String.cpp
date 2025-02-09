#include <bits/stdc++.h>
bool isMirrorLetters(char ch)
{
	if(ch=='A' || ch=='H' || ch=='I' || ch=='M' || ch=='O'|| ch=='T' || ch=='U' || ch=='V' || ch=='W' || ch=='X' || ch=='Y')
	return true;
	return false;
}
bool isReflectionEqual(string &s)
{
	int l=0;
	int r=s.length()-1;
	while(l<=r)
	{
		if(s[l]!=s[r] || !isMirrorLetters(s[l]) || !isMirrorLetters(s[r]))
		return false;
		l++;
		r--;
	}
	return true;
}
