#LeetCode: 402

class Solution {
public:
    string removeKdigits(string num, int k)
     {
        //Keep Smaller Digits At The front
        if(num.length()==k) return "0";
        string ans="";
        stack<char>st;
        for(int  i=0;i<num.length();i++)
        {
            while(!st.empty() && k>0 && st.top()-'0'>num[i]-'0')
            {
                
                    st.pop();
                    k--;
                     
            }    
            st.push(num[i]);
        }
        // while(st.top()-'0')
        // If Input Is 123456 Then No Number Will Be Removed
        //If So Remove Top 3 Elements From Stack Which Must Be The Greatest
        while(k>0)
        {
            st.pop();
            k--;
        }
        //If The Stack Had Remaining Elements Push It To The String
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        //Remove Leading Zeros
        while(ans.length()!=0 && ans.back()=='0')
        {
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        //After Removing Leading Zeros If The String Is Empty Then Return "0"
        if(ans.length()==0)
        return "0";
        return ans;
    }
};
