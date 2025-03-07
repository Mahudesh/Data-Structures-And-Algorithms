// void dfs(int start, vector<vector<int>>& adj, vector<bool>& visited)
// {
//     visited[start]=true;
//     for(auto it : adj[start])
//     {
//         if(!visited[it])
//         {
//             dfs(it,adj,visited);
//         }
//     }
// }

class DisjointSet
{
	

	public:
    vector<int>rank,parent;
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
int findNumOfProvinces(vector<vector<int>>& roads, int n) 
{
    // Write your code here.
    // vector<vector<int>>adj(n+1);
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         if(roads[i][j]==1 && i!=j)
    //         {
    //             adj[i+1].push_back(j+1);
    //             adj[j+1].push_back(i+1);
    //         }
    //     }
    // }

    // int cnt=0;
    // vector<bool>visited (n+1,false);
    // for(int i=1;i<=n;i++)
    // {
    //     if(!visited[i])
    //     {
    //         cnt++;
    //         dfs(i,adj,visited);
    //     }
    // }

    DisjointSet ds(n);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(roads[i][j]==1)
            {
		    //Every 0 To 1 Is A City So Connect The Road From City 0 To City 1
                ds.UnionByRank(i+1,j+1);
            }
        }
    }

    int cnt=0;
    for(int u=1;u<=n;u++)
    {
        // If He Is The Super Boss Then It Is The New Province

        // if(ds.findParent(u)==u)
        // cnt++;

        if(ds.parent[u]==u)
        cnt++;
    }
    return cnt;
}
