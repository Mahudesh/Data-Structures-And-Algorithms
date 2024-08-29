class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k)
     {
        unordered_map<int,int>Map;
        int sum=0;
        int cnt=0;
        Map[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
            int rem=((sum%k)+k)%k;
            if(Map.find(rem)!=Map.end())
            {
                cnt=cnt+Map[rem];
            }
            Map[rem]++;
        }
        return cnt;
    }
};
