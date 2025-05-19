class Solution {
public:
    int maxSumMinProduct(vector<int>& nums)
    {
        int n=nums.size();
        vector<int>prevSmaller(n,0);
        vector<int>nextSmaller(n,n-1);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && nums[st.top()]>=nums[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                nextSmaller[i]=st.top()-1;
            }
            st.push(i);
        }
        while(!st.empty())
        st.pop();

        for(int i=0;i<n;i++)
        {
            while(!st.empty() && nums[st.top()]>=nums[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                prevSmaller[i]=st.top()+1;
            }
            st.push(i);
        }
        long long mod=1e9+7;
        vector<long long int>prefixSum(n+1,0);
        for(int i=0;i<n;i++)
        {
            prefixSum[i+1]=prefixSum[i]+(nums[i]);
        }
        long long maxi=0;
        //Use The Prefix Sum Concept To Find The Sum Of The Array Between The Valid Ranges
        for(int i=0;i<n;i++)
        {
            int left=prevSmaller[i];
            int right=nextSmaller[i];
            long long sum=(prefixSum[right+1]-prefixSum[left]);
            maxi=max(maxi,sum*nums[i]);
        }
        return maxi%mod;
    }
};
