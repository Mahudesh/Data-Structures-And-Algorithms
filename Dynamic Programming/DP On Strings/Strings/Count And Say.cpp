#include <bits/stdc++.h> 
string countAndSay(int n)
{
	if(n==1)
	return "1";

	string prev=countAndSay(n-1);

	//fdigit - frequencydigit

	//1122

	int len=prev.length();
	int freq=1;
	string temp="";
	for(int i=1;i<len;i++)
	{
		if(prev[i]==prev[i-1])
		{
			freq++;
		}
		else
		{
			char ch=freq+'0';
			temp=temp+ch;
			temp=temp+prev[i-1];
			freq=1;//For Current Frequency Of Element
		}
	}
	char ch=freq+'0';
	temp=temp+ch;
	temp=temp+(prev[len-1]);

	return temp;

}
string writeAsYouSpeak(int n) 
{
	// Write your code here.	
	return countAndSay(n);
}
