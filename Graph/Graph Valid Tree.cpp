#include <bits/stdc++.h> 
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited)
{
    visited[node]=true;
    for(auto it : adj[node])
    {
        if(!visited[it])
        dfs(it,adj,visited);
    }
}
bool detectCycle(int node, int parent, vector<bool>& visited, vector<vector<int>>& adj)
{
    visited[node]=true;
    for(auto it : adj[node])
    {
        if(!visited[it])
        {
            if(detectCycle(it,node,visited,adj))
            return true;
        }
        else if(visited[it] && it!=parent && parent!=-1)
        {
            return true;
        }
    }
    return false;
}
bool checkgraph(vector<vector<int>> edges, int n, int m)
{
    // write your code here
    if(m!=n-1)
    return false;
    vector<vector<int>>adj(n);
    for(auto it : edges)
    {
        int u=it[0];
        int v=it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool>visited(n,false);
    dfs(0,adj,visited);
    for(auto it : visited)
    {
        if(!it)
        return false;
    }
    fill(visited.begin(),visited.end(),false);
    if(detectCycle(0,-1,visited,adj))
    return false;
    return true;
}
