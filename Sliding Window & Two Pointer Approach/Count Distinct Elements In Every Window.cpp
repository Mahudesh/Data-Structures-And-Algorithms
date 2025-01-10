Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k)
    {
        // code here.
        unordered_map<int,int>Map;
        int l=0;
        int r=0;
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            Map[arr[i]]++;
        }
        ans.push_back(Map.size());
        r=k;
        while(r<arr.size())
        {
            Map[arr[r]]++;
            Map[arr[l]]--;
            if(Map[arr[l]]<=0)
            Map.erase(arr[l]);
            l++;
            r++;
            ans.push_back(Map.size());
        }
        return ans;
        
    }
