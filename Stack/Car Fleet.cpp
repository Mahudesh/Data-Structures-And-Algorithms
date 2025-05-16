class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed)
    {
        int n=position.size();
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++)
        {
            arr.push_back({position[i],speed[i]});
        }
        sort(arr.begin(),arr.end());

        stack<double>st;
        for(int i=n-1;i>=0;i--)
        {
            double timeTaken=(double)(target-arr[i].first)/(double)arr[i].second;
            // cout<<timeTaken<<endl;

            //Dont Consider The Cars Which Has Less Time To Reach The Target
            //Since It Will Intersect With The Ahead One Cars
            if(!st.empty() && timeTaken<=st.top())
            {
                continue;
            }
            
            st.push(timeTaken);

        }
        return st.size();

    }
};
