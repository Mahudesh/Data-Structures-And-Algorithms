class DisjointSet
{
	vector<int>rank,parent;

	public:
	DisjointSet(int n)
	{
		parent.resize(n+1,0);
		for(int i=0;i<=n;i++)
		parent[i]=i;
		rank.resize(n+1,0);
	}

	int findParent(int node)
	{
		if(parent[node]==node)
		return node;

		return parent[node] = findParent(parent[node]);
	}
	void UnionByRank(int u, int v)
	{
		int ult_u=findParent(u);
		int ult_v=findParent(v);

		if(ult_u==ult_v)
		return;

		if(rank[ult_u]<rank[ult_v])
		{
			parent[ult_u]=ult_v;
		}
		else if(rank[ult_v]<rank[ult_u])
		{
			parent[ult_v]=ult_u;
		}
		else
		{
			parent[ult_u]=ult_v;
			rank[ult_v]++;
		}
	}
};
bool static comp(vector<int>& a, vector<int>& b)
{
	return a[2]<b[2];
}
int kruskalMST(int n, vector<vector<int>> &edges)
{
	// Write your code here.

	int sum=0;

	sort(edges.begin(),edges.end(),comp);

	DisjointSet ds(n);
	for(int i=0;i<edges.size();i++)
	{
		int u=edges[i][0];
		int v=edges[i][1];
		int wt=edges[i][2];

		if(ds.findParent(u)!=ds.findParent(v))
		{
			sum+=wt;
			ds.UnionByRank(u,v);
		}
	}
	return sum;
}
