class Solution {
public:
    int sumHighestAndLowestFrequency(vector<int>& nums)
	 {
		int maxi=*max_element(nums.begin(),nums.end());
		vector<int>hash(maxi+1,0);
		for(int i=0;i<nums.size();i++)
		{
			hash[nums[i]]++;
		}
		int lfreq=INT_MAX;
		int hfreq=INT_MIN;
		int l=0;
		int s=0;
		for(int i=0;i<hash.size();i++)
		{
			if(hash[i]==0)
			continue;
			if(hfreq<hash[i])
			{
				hfreq=hash[i];
				// l=i;
				s=i;
			}
			if(lfreq>hash[i])
			{
				lfreq=hash[i];
				l=i;
			}
		}
		return lfreq+hfreq;
    }
};
