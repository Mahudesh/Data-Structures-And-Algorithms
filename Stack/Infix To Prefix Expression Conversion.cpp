#include<bits/stdc++.h>
using namespace std;
int precedence(char ch)
{
    if(ch=='^') return 3;
    else if(ch=='*'|| ch=='/') return 2;
    else if(ch=='+' || ch=='-') return 1;
    return -1;
}
string infixtoprefix(string&str)
{
    string ans="";
    stack<char>st;
    for(int i=0;i<str.length();i++)
    {
        char ch=str[i];
        
        if(ch>='A'&&ch<='Z' || ch>='a'&&ch<='z' || ch>='0'&&ch<='9')
        {
            ans+=ch;
        }
        else if(ch=='(')
        {
            st.push('(');
        }
        else if(ch==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                ans+=st.top();
                st.pop();
            }
            if(st.top()=='(')
            st.pop();
            else
            return "Invalid String";
        }
        else
        {
            if(ch=='^')
            {
                while(!st.empty() && precedence(ch)<=precedence(st.top()))
                {
                    ans+=st.top();
                    st.pop();
                }   
                st.push(ch);
            }
            else
            {
                while(!st.empty() && precedence(ch)<precedence(st.top()))
                {
                    ans+=st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
    }
    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    string str="A*B+C/D";
    string reversed="";
    for(int i=str.length()-1;i>=0;i--)
    {
        if(str[i]=='(')
        {
            reversed+=')';
        }
        else if(str[i]==')')
        {
            reversed+='(';
        }
        else
        {
            reversed+=str[i];
        }
    }
    string ans=infixtoprefix(reversed);
    for(auto it: ans)
    cout<<it;
}
