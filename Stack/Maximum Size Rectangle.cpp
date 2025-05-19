class Solution {
public:
int f(vector<int>& arr)
{
    stack<int>st;
    int n=arr.size();
    vector<int>prevSmaller(n,0);
    vector<int>nextSmaller(n,n-1);
    for(int i=0;i<arr.size();i++)
    {
        while(!st.empty() && arr[st.top()]>=arr[i])
        st.pop();
        if(!st.empty())
        prevSmaller[i]=st.top()+1;
        st.push(i);
    }
    while(!st.empty())
    st.pop();
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && arr[st.top()]>=arr[i])
        st.pop();
        if(!st.empty())
        nextSmaller[i]=st.top()-1;
        st.push(i);
    }
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int h=arr[i];
        int w=nextSmaller[i]-prevSmaller[i]+1;
        maxi=max(maxi,h*w);
    }
    return maxi;
}
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int n=matrix.size();
        int m=matrix[0].size();
        // vector<vector<int>>arr(n, vector<int>(m+1,0));
        vector<int>arr(m,0);
        int maxi=INT_MIN;
        // arr=matrix[0];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')
                arr[j]++;
                else
                arr[j]=0;
            }
            maxi=max(maxi,f(arr));
        }
        return maxi;
    }
};
