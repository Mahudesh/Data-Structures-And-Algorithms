#include<stack>
int precedence(char ch)
{
	if(ch=='^') return 3;
	else if(ch=='*' || ch=='/') return 2;
	else if(ch=='+' || ch=='-') return 1;
	return -1;
}
string conversion(string& str)
{
	stack<char>st;
	int n=str.length();
	string ans="";
	for(int i=0;i<n;i++)
	{
		char ch=str[i];

		//If It Is An Operand
		if(ch>='a' && ch<='z' || ch>='A'&&ch<='Z' || ch>='0'&&ch<='9')
		{
			ans=ans+ch;
		}
		else if(ch=='(')
		{
			st.push(ch);
		}
		else if(ch==')')
		{
			while(!st.empty() && st.top()!='(')
			{
				ans=ans+st.top();
				st.pop();
			}
			st.pop();
		}
		else
		{
			//Condition for Operators
			while(!st.empty() && precedence(ch)<=precedence(st.top()))
			{
				ans=ans+st.top();
				st.pop();
			}
			st.push(ch);
		}
	}
	while(!st.empty())
	{
		ans=ans+st.top();
		st.pop();
	}
	return ans;
}

string infixToPostfix(string exp)
{
	// Write your code here
	return conversion(exp);
}
