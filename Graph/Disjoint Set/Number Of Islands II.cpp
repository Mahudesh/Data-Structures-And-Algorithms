class DisjointSet
{
	vector<int>parent,rank;
	public:
	DisjointSet(int n)
	{
		parent.resize(n+1);
		for(int i=0;i<=n;i++)
		parent[i]=i;
		rank.resize(n+1,0);
	}
	int findParent(int node)
	{
		if(node==parent[node])
		return node;

		return parent[node]=findParent(parent[node]);
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
const int drow[4]={1,-1,0,0};
const int dcol[4]={0,0,1,-1};
vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q)
{
	// Write your code here.
	vector<int>ans;
	vector<vector<bool>>visited(n, vector<bool>(m,false));
	int cnt=0;
	DisjointSet ds(n*m);
	for(int i=0;i<q.size();i++)
	{
		int row=q[i][0];
		int col=q[i][1];
		if(visited[row][col])
		{
			ans.push_back(cnt);
			continue;
		}
		else
		{
			visited[row][col]=true;
			cnt++;

				for(int d=0;d<4;d++)
				{
					int nxtRow=row+drow[d];
					int nxtCol=col+dcol[d];
					//Check For Adjacent Node To Be Valid
					if(nxtRow>=0 && nxtCol>=0 && nxtRow<n && nxtCol<m)
					{
						//Check For Adjacent Node To Be An Island
						if(visited[nxtRow][nxtCol]==true)
						{
							//Formula For Calculating The Node Number
							int node=(row*m)+col;
							int adjnode=(nxtRow*m)+nxtCol;
							//Check For Adjacent Node Should Not Be In Same Island
							//If So I Dont Need To Connect Both And Reduce The Cnt Of Islands
							//If Not In Same Island Then All Conditions Are Satisfied
							//And Hence Connect The Component To Make A Combined Island
							if(ds.findParent(node)!=ds.findParent(adjnode))
							{
								cnt--;
								ds.findUnion(node,adjnode);
							}
						}
					}
				}
			
			ans.push_back(cnt);
		}
		
	}
	return ans;

}
