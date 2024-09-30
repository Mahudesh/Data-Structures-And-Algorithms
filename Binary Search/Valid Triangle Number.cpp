    class Solution {
    public:
        int triangleNumber(vector<int>& nums) 
        {
            BruteForce
            for(int i=0;i<n-2;i++)
            {
                for(int j=i+1;j<n-1;j++)
                {
                    for(int k=j+1;k<n;k++)
                    {
                        if (nums[i]+nums[j]>nums[k])
                        ans++;
                    }
                }
            }
            Optimal
            int ans=0;
            int n=nums.size();
            //First Sort The Array For Optimal Counting Of Inbetween Pairs
            sort(nums.begin(), nums.end());
            //Fix The Largest Third Pair(c) and ehck for other two pairs a and b
            for(int k=nums.size()-1;k>=2;k--)
            {
                int left=0;
                int right=k-1;
                //Use The Binary Search To Find Other Two Pairs
                while(left<=right)
                {
                    if(nums[left]+nums[right]>nums[k])
                    {
                        ans=ans+(right-left);
                        right--;
                    }
                    else
                    {
                        //If Sum Is Low By Moving Only Left I Can Find The More Higher Sum
                        //Since The Array Is Sorted
                        left++;
                    }
                }
            }
            return ans;
        }
}
