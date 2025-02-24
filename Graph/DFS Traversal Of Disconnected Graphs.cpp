void dfs(int start, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& temp)
{
    visited[start]=true;
    temp.push_back(start);

    for(auto ele : adj[start])
    {
        if(!visited[ele])
        {
            dfs(ele,adj,visited,temp);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>>adj(V);

    for(int i=0;i<E;i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //DFS For All Nodes Since It Is Disconnected Graph Into Components
    vector<bool>visited(V,false);
    vector<vector<int>>ans;
    for(int i=0;i<V;i++)
    {
        vector<int>temp;
        if(!visited[i])
        {
            dfs(i,adj,visited,temp);
            ans.push_back(temp);
        }
    }
    return ans;


}
