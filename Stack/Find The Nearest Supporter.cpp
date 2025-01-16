#include <bits/stdc++.h> 
vector<int> prevSmall(vector<int> arr, int n) 
{
    vector<int>prevSmaller(n,-1);
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && arr[st.top()]>=arr[i])
        {
            st.pop();
        }
        if(!st.empty())
        {
            prevSmaller[i]=arr[st.top()];
        }
        st.push(i);
    }
    return prevSmaller;
}
