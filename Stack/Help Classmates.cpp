
class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
        vector<int>nextSmaller(n,-1);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()>=arr[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                nextSmaller[i]=st.top();
            }
            st.push(arr[i]);
        }
        return nextSmaller;
    } 
