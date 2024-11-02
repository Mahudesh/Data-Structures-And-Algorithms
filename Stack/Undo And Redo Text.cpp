#include<bits/stdc++.h>
using namespace std;
stack<string>temp;
stack<string>st;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string comm;
        cin>>comm;
        if(comm=="ADD")
        {
            cin.ignore();
            string val;
            getline(cin,val);
            st.push(val);
            while(!temp.empty())
            {
                temp.pop();
            }
        }
        else if(comm=="UNDO")
        {
            if(!st.empty())
            {
                temp.push(st.top());
                st.pop();
            }
        }
        else if(comm=="REDO")
        {
            if(!temp.empty())
            {
                st.push(temp.top());
                temp.pop();
            }
        }
    }
    stack<string>ans;
    while(!st.empty())
    {
        ans.push(st.top());
        st.pop();
    }
    while(!ans.empty())
    {
        cout<<ans.top()<<"\n";
        ans.pop();
    }
}
