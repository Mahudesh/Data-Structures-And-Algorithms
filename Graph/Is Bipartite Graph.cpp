class Solution {
public:
bool Check(int start,vector<vector<int>>& adj, vector<int>& colored)
{
        queue<int>q;
        q.push(start);
        colored[start]=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();

            for(auto adjacent : adj[node])
            {
                if(colored[adjacent]==-1)
                {
                    //If Adjacent Is Not Colored Then Color It With Opposite Color Of Current Node 
                    colored[adjacent]=!colored[node];
                    q.push(adjacent);
                }
                else if(colored[adjacent]!=-1)
                {
                    //If Adjacent Is Colored Then Both Adjacent And Current Dont Have Same Color
                    if(colored[adjacent]==colored[node])
                    return false;
                }
            }
        }
        return true;
}
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        int m=graph[0].size();
        vector<int>colored(n,-1);
        for(int i=0;i<n;i++)
        {
            if(colored[i]==-1)
            {
                if(!Check(i,graph,colored))
                return false;
            }
        }
       
        return true;
    }
};

//DFS Solution
bool dfs(int start,int color, vector<vector<int>>& adj, vector<int>& colored)
{
	colored[start]=color;

	for(auto adjacent : adj[start])
	{
		if(colored[adjacent]==-1)
		{
			if(dfs(adjacent,!color,adj,colored)==false)
			return false;
		}
		else if(colored[adjacent]!=-1)
		{
			 if(colored[adjacent]==colored[start])
			 return false;
		}
	}
	return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges) 
{
	// Write your code here.
	int n=edges.size();
	vector<vector<int>>adj(n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<edges[i].size();j++)
		{
			if(edges[i][j]==1)
			{
				int u=i;
				int v=j;
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
		}


	}
	vector<int>colored(n,-1);
	for(int i=0;i<n;i++)
	{
		if(colored[i]==-1){
		if(!dfs(i,0,adj,colored))
		return false;
		}
		
	}
	return true;
}
// 1 2 3
// 0 
