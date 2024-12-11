Class Solution {
  public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& st) 
    {
        // code here..
        stack<int>temp;
        int mid=floor(st.size()/2);
        for(int i=1;i<=mid;i++)
        {
            temp.push(st.top());
            st.pop();
        }
        st.pop();
        while(!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
    }
};
