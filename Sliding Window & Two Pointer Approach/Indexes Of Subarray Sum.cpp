Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target)
    {
        // code here
        unordered_map<int,int>Map;
        int sum=0;
        vector<int>ans;
        for(int i=0;i<arr.size();i++)
        {
            sum=sum+arr[i];
            if(sum==target)
            {
                return {1,i+1};
            }
            int rem=sum-target;
            if(Map.find(rem)!=Map.end())
            {
                // return {Map[rem]+1,i+1};
                ans.push_back(Map[rem]+2);
                ans.push_back(i+1);
                return ans;
            }
            if(Map.find(sum)==Map.end())
            Map[sum]=i;
        }
        ans.push_back(-1);
        return ans;
    }
};
