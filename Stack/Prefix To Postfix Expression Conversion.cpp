class Solution {
  public:
  string prefixToPostfix(string str)
  {
      stack<string>st;
      for(int i=str.length()-1;i>=0;i--)
      {
          if(isalnum(str[i]))
          {
              st.push(string(1,str[i]));
          }
          else
          {
              if(st.size()<2) return "Invalid String";
              string t1=st.top();
              st.pop();
              string t2=st.top();
              st.pop();
              string temp=t1+t2+str[i];
              st.push(temp);
          }
      }
      if(st.size()>1)
      return "Invalid String";
      return st.top();
  }
    string preToPost(string pre_exp) 
    {
        return prefixToPostfix(pre_exp);
    }
};
