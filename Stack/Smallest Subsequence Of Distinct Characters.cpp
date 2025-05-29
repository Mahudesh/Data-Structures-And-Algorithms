class Solution {
public:
    string smallestSubsequence(string s)
    {
        stack<char>st;
        int len=s.length();
        vector<bool>visited(26,false);
        vector<int>lastSeen(26);
        for(int i=0;i<len;i++)
        {
            lastSeen[s[i]-'a']=i;
        }
        for(int i=0;i<len;i++)
        {
            if(visited[s[i]-'a']==true)
            continue;

            while(!st.empty() && st.top()>s[i] && lastSeen[st.top()-'a']>i)
            {
                visited[st.top()-'a']=false;
                st.pop();
            }
            st.push(s[i]);
            visited[s[i]-'a']=true;
        }
        string ans="";
        while(!st.empty())
        {
            char ch=st.top();
            st.pop();
            ans.push_back(ch);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
