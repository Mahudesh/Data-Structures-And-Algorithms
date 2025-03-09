class Solution {
public:
int timer = 1;
void dfs(int node,int parent,vector<vector<int>>& adj, vector<int>& tin, vector<int>& low, vector<vector<int>>& bridges, vector<bool>& visited)
{
    visited[node]=true;
    tin[node]=timer;
    low[node]=timer;
    timer++;

    for(auto adjacent : adj[node])
    {
        if(adjacent==parent)
        continue;
        if(!visited[adjacent])
        {
            dfs(adjacent,node,adj,tin,low,bridges,visited);
            low[node]=min(low[node],low[adjacent]);

            if(tin[node]<low[adjacent])
            {
                bridges.push_back({node,adjacent});
            }
        }
        else if(visited[adjacent])
        {
            low[node]=min(low[node],low[adjacent]);
        }
    }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        vector<int>tin(n);
        vector<int>low(n);
        vector<vector<int>>adj(n);
        vector<bool>visited(n,false);
        for(auto it : connections)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>>bridges;
        dfs(0,-1,adj,tin,low,bridges,visited);
        return bridges;
    }
};
