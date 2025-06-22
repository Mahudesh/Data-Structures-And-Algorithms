class Solution {
  public:
  void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& temp)
  {
      visited[node]=true;
      temp.push_back(node);
      
      for(auto it : adj[node])
      {
          if(!visited[it])
          dfs(it,adj,visited,temp);
      }
  }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges)
    {
        // code here
        vector<vector<int>>ans;
        vector<vector<int>>adj(V);
        for(auto it : edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                vector<int>temp;
                dfs(i,adj,visited,temp);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
