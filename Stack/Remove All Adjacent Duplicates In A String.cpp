class Solution {
public:
    string removeDuplicates(string s)
     {
        stack<char>st;
        bool flag=false;
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
            while(!st.empty() && st.top()==ch)
            {
                st.pop();
                flag=true;
            }
            if(!flag)
            st.push(s[i]);
            else
            flag=false;
        }
        string ans="";
        if(st.empty())
        return ans;
        while(!st.empty())
        {
            ans=ans+st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        // else
        return ans;
    }
};
