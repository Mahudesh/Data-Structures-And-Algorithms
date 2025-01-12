class Solution {
public:
    int secondMostFrequentElement(vector<int>& nums) 
    {
      int maxi=*max_element(nums.begin(),nums.end());
	  vector<int>hash(maxi+1,0);
	  for(int i=0;i<nums.size();i++)
	  {
		hash[nums[i]]++;
	  }
	  int l=-1;
	  int sl=-1;
	  int cnt=0;
	  int lfreq=0,slfreq=0;
	  for(int i=0;i<hash.size();i++)
	  {
		cnt=hash[i];
		if(cnt==0)
		continue;
		if(cnt>lfreq)
		{
			sl=l;
			slfreq=lfreq;
			l=i;
			lfreq=cnt;
		}
		else if(cnt<lfreq && cnt>slfreq)
		{
			sl=i;
			slfreq=cnt;
		}
	  }
	  return sl;

    }
};
