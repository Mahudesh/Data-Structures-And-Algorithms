class Solution {
  public:
  string conversion(string str)
  {
      stack<string>st;
      for(int i=str.length()-1;i>=0;i--)
      {
          //Run Backwwards
          char ch=str[i];
          if(ch>='A' && ch<='Z' || ch>='a' && ch<='z' || ch>='0'&&ch<='9')
          {
              st.push(string(1,ch));
          }
          else
          {
              string t1=st.top();
              st.pop();
              string t2=st.top();
              st.pop();
              string temp="(" + t1 + string(1,ch) + t2 + ")";
              st.push(temp);
          }
      }
      return st.top();
  }
    string preToInfix(string pre_exp) 
    {
        // Write your code here
        return conversion(pre_exp);
    }
};
