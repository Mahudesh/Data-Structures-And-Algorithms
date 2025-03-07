class DisjointSet
{
	vector<int>rank,parent;
	public:

	DisjointSet(int n)
	{
		rank.resize(n+1,0);
		parent.resize(n+1);
		for(int i=0;i<n;i++)
		parent[i]=i;
	}

	int findParent(int node)
	{
		if(node==parent[node])
		return node;

		return parent[node] = findParent(parent[node]);
	}
	void findUnion(int u, int v)
	{
		int ult_u=findParent(u);
		int ult_v=findParent(v);

		if(ult_u==ult_v)
		return;
		if(rank[ult_u]<rank[ult_v])
		parent[ult_u]=ult_v;
		else if(rank[ult_v]<rank[ult_u])
		parent[ult_v]=ult_u;
		else
		{
			parent[ult_u]=ult_v;
			rank[ult_v]++;
		}
	}

};
vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
{
	// Write your code here.
	int n=accounts.size();
	DisjointSet ds(n);
	vector<vector<string>>ans;
	unordered_map<string,int>Map;
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<accounts[i].size();j++)
		{
			string mail=accounts[i][j];
				if(Map.find(mail)==Map.end())
				{
					Map[mail]=i;
				}
				else
				{
					ds.findUnion(Map[mail],i);
				}
		}
	}

	vector<vector<string>>temp(n);
	for(auto pair : Map)
	{
		string mail=pair.first;
		int node=pair.second;

		int ult_parent=ds.findParent(node);

		temp[ult_parent].push_back(mail);
		
	}

	// vector<vector<string>>ans;

	for(int i=0;i<n;i++)
	{
		if(temp[i].size()==0)
		continue;

		sort(temp[i].begin(),temp[i].end());

		vector<string>t;
		t.push_back(accounts[i][0]);
		for(auto it : temp[i])
		t.push_back(it);
		ans.push_back(t);
	}
	return ans;
	

}
