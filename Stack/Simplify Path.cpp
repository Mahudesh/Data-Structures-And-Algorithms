class Solution {
public:
    string simplifyPath(string path)
    {
        // /..//
        stack<string>st;
        path.push_back('/');
        string curr="";
        for(auto ch : path)
        {
            if(ch=='/')
            {
                if(curr==".." && !st.empty())
                {
                    st.pop();
                }
                else if(curr!="" && curr!="." && curr!="..")
                {
                    st.push(curr);
                }
                curr="";
            }
            else
            {
                curr.push_back(ch);
            }
        }
        string ans="";
        // ans.push_back('/');
        vector<string>res;
        while(!st.empty())
        {
            string t=st.top();
            st.pop();
            res.push_back(t);
        }
        reverse(res.begin(),res.end());

        ans.push_back('/');
        for(int i=0;i<res.size();i++)
        {
            ans=ans+res[i];
            if(i!=res.size()-1)
            ans.push_back('/');
        }

        return ans;

    }
};
