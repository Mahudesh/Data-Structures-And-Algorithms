#LeetCode: 907
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr)
     {
        //  long long sum=0;
        //  int mod=(int)1e9+7;
        // // sum+=accumulate(arr.begin(),arr.end())
        // for(long long i=0;i<arr.size();i++)
        // {
        //     int mini=arr[i];
        //     for(long long j=i;j<arr.size();j++)
        //     {
        //         mini=min(mini,arr[j]);
        //         sum+=mini%mod;
        //     }
        // }
        // return sum;
        int n=arr.size();
        vector<int>prevSmaller(n);
        vector<int>nextSmaller(n);
        stack<int>st;
        //Always Find The Previous Equal To Or Smaller Element
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
            {
                st.pop();
            }
            if(!st.empty())
            prevSmaller[i]=st.top();
            else
            prevSmaller[i]=-1;
            st.push(i);
        }
        while(!st.empty())
        {
            st.pop();
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            if(!st.empty())
            nextSmaller[i]=st.top();
            else
            nextSmaller[i]=n;
            st.push(i);
        }
        long long sum=0;
        long long mod=(1e9)+7;
        for(int i=0;i<n;i++)
        {
            long long leftContributions=i-prevSmaller[i];
            long long rightContributions=nextSmaller[i]-i;
            sum=(sum+leftContributions*rightContributions*arr[i])%mod;

        }
        return sum;


    }
};
