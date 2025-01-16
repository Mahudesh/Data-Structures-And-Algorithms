static bool comp(pair<char,int>&a, pair<char,int>&b)
{
	// if(a.second==b.second)
	// return a.first<b.first;

	return a.second>b.second;
}
string sortByFrequency(int n, string& s)
{
	// Write Your Code here
	unordered_map<char,int>Map;
	for(int i=0;i<s.length();i++)
	{
		s[i]=tolower(s[i]);
		Map[s[i]]++;
	}

	vector<pair<char,int>>p(Map.begin(),Map.end());
	sort(p.begin(),p.end(),comp);
	s.clear();

	
	for(int i=0;i<p.size();i++)
	{
		// cout<<p[i].first<<"-> "<<p[i].second<<endl;
		
		char c=p[i].first;
		int t=p[i].second;
		// string ch=(p[i].first,p[i].second);
		string ch = string(t,c);
		// s.push_back(ch);
		s=s+ch;
	}
	
	// cout<<s;

	
	return s;
}
