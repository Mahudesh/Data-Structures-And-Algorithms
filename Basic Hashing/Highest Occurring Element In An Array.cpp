class Solution {
public:
    int mostFrequentElement(vector<int>& nums)
     {
    //    vector<int>hash(1e4+1,0);
	int maxi=*max_element(nums.begin(),nums.end());
	vector<int>hash(maxi+1,0);
	   int maxEle=-1;
	   int maxFreq=-1;
	   for(int i=0;i<nums.size();i++)
	   {
			hash[nums[i]]++;
			// maxEle=nums[i];
	   }
	   for(int i=0;i<=maxi;i++)
	   {
		if(hash[i]>maxFreq)
		{
			maxFreq=hash[i];
			maxEle=i;
		}
	   }

	   return maxEle;
    }
};
