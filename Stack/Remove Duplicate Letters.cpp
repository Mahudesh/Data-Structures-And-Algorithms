class Solution {
public:

    string removeDuplicateLetters(string s)
    {
        //Increasing Monotonic Stack + Last Seen of A Character + Visited Of Elements
        stack<char>st;
        unordered_map<char,int>Map;
        for(int i=0;i<s.length();i++)
        {
            Map[s[i]]=i;
        }
        vector<bool>visited(26,false);
        for(int i=0;i<s.length();i++)
        {
            //If The Character Was Already Seen Then No Use Of Storing It In Answer
            if(visited[s[i]-'a']==true)
            {
                continue;
            }
            while(!st.empty() && st.top()>s[i] && Map[st.top()]>i)
            {
                //If It Disturbs Your Lexicographical Order 
                //And If The Character Can Be Find Later Then Remove It And Make It As Unseen Character
                visited[st.top()-'a']=false;
                st.pop();
            }
            st.push(s[i]);
            visited[s[i]-'a']=true;
        }
        string ans="";
        while(!st.empty())
        {
            ans=ans+st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
