class Solution {
public:
void dfs(int node,vector<bool>& visited, vector<vector<int>>& adj)
{
    visited[node]=true;
    for(auto it : adj[node])
    {
        if(!visited[it])
        dfs(it,visited,adj);
    }
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
        vector<bool>visited(n,false);
        vector<vector<int>>adj(n);
        for(auto it: edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(source,visited,adj);
        return visited[destination];
    }
};
