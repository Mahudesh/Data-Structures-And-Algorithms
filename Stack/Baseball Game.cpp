class Solution {
public:
    int calPoints(vector<string>& operations)
    {
        stack<int>st;
        int prev=-1;
        int secprev=-1;
        for(int i=0;i<operations.size();i++)
        {
            string str=operations[i];
            if(str=="C")
            {
                st.pop();
            }
            else if(str=="D")
            {
                int t=st.top();
                st.push(2*t);
            }
            else if(str=="+")
            {
                if(st.size()>=2){
                int t1=st.top();
                st.pop();
                int t2=st.top();
                st.push(t1);
                st.push(t1+t2);
                }
            }
            else
            {
                st.push(stoi(str));
            }
        }
        int sum=0;
        while(!st.empty())
        {
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};
