int assignCookie(vector<int> &greed, vector<int> &size) 
{
	// Write your code here.
	sort(greed.begin(),greed.end());
	sort(size.begin(),size.end());
	int l=0;
	int r=0;
	while(r<size.size() && l<greed.size())
	{
		if(size[r]>=greed[l])
		{
			l++;
		}
		r++;

	}
	return l;
}
