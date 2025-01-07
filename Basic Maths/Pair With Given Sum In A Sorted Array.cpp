Solution {
  public:
    int countPairs(vector<int> &arr, int target)
    {
        // Complete the function
        //Similar To Number Of Subarray Sum Equals K
        //Number Of Pairs With Given Sum Equals Target
        unordered_map<int,int>Map;
        int cnt=0;
        for(int i=0;i<arr.size();i++)
        {
            int moreNeeded=target-arr[i];
            if(Map.find(moreNeeded)!=Map.end())
            {
                cnt=cnt+Map[moreNeeded];
            }
            Map[arr[i]]++;
        }
        return cnt;
    }
};
