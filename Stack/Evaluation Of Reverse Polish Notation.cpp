#Evaluation Of Postfix Expression
 public:
    int evaluate(string str)
    {
        stack<int>st;
        for(int i=0;i<str.length();i++)
        {
            if(isdigit(str[i]))
            {
                st.push(str[i]-'0');
            }
            else
            {
                int t1=st.top();
                st.pop();
                int t2=st.top();
                st.pop();
                int result=0;
                switch(str[i])
                {
                    case '+':
                     result=t2+t1;
                     break;
                    case '-':
                     result=t2-t1;
                     break;
                    case '*':
                     result=t2*t1;
                     break;
                    case '/':
                     result=t2/t1;
                     break;
                }
                st.push(result);
            }
        }
        return st.top();
    }
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        return evaluate(S);
    }
