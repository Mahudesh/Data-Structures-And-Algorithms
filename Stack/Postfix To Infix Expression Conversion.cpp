class Solution {
  public:
  string conversion(string str)
  {
      stack<string>st;
      for(int i=0;i<str.length();i++)
      {
          string ch=string(1,str[i]);
          if(isalnum(str[i]))
          {
              st.push(ch);
          }
          else
          {
              string t1=st.top();
              st.pop();
              string t2=st.top();
              st.pop();
              
              string temp="(" + t2 + ch + t1 + ")";
              st.push(temp);
              temp="";
          }
      }
      return st.top();
  }
    string postToInfix(string exp) 
    {
        // Write your code here
        return conversion(exp);
    }
};
