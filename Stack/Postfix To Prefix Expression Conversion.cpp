class Solution {
  public:
  string postfixToPrefix(string str)
  {
      stack<string>st;
      for(int i=0;i<str.length();i++)
      {
          if(isalnum(str[i]))
          {
              st.push(string(1,str[i]));
          }
          else
          {
              string t1=st.top();
              st.pop();
              string t2=st.top();
              st.pop();
              string temp=str[i]+t2+t1;
              st.push(temp);
          }
      }
      return st.top();
  }
    string postToPre(string post_exp)
    {
        return postfixToPrefix(post_exp);
    }
};
