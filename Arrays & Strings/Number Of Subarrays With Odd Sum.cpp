class Solution {
public:
    int numOfSubarrays(vector<int>& arr) 
    {
        int odd=0;
        int even=0;
        int cnt=0;
        int mod=1e9+7;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]%2==0)
            even++;
            else
            {
                swap(odd,even);
                odd++;
            }
                cnt=(cnt+odd)%mod;
        }
        return cnt;
    }
};
