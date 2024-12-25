class Solution {
public:
    int minAddToMakeValid(string s) 
    {
        //Always Try To Keep What I Can Not Touch
        //Here I Cannot Touch The Valid Paranthesis
        //If A Paranthesis Is Valid Then It Uses 2 Brackets
        //So Make Sure U Multiply The Valid Paranthesis By Two
        int cnt=0;
        stack<char>st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty())
                continue;

                if(st.top()=='(' && s[i]==')')
                {
                    st.pop();
                    cnt++;
                }
                else
                continue;
                
            }
        }
        //If A Paranthesis Is A Valid Then It Will Contain Two Valid Brackets
        //So For Every Valid Multiply It By Two
        //Subtract The Total Length - Valid Bracket Will Give You Minimum Insertions
        int valid=cnt*2;
        return s.length()-valid;
    }
};
