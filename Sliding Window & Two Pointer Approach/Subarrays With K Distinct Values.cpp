int helper(vector<int>& arr, int n, int k)
{
    int l=0;
    int r=0;
    unordered_map<int,int>Map;
    int cnt=0;
    while(r<arr.size())
    {
        Map[arr[r]]++;

        while(Map.size()>k)
        {
            Map[arr[l]]--;
            if(Map[arr[l]]<=0)
            Map.erase(arr[l]);
            l++;
        }
        if(Map.size()<=k)
        {
            cnt=cnt+(r-l+1);
        }
        r++;
    }
    return cnt;
}
int kDistinctSubarrays(vector<int> &arr, int n, int k)
{
    // Write your code here
    int a=helper(arr,n,k-1);
    int b=helper(arr,n,k);
    return b-a;
}
