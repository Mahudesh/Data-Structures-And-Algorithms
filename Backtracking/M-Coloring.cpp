 Solution {
  public:
  bool isSafe(int node, int col, vector<vector<int>>& adj, vector<int>& colored, int v)
  {
      for(auto it : adj[node])
      {
          if(it!=node && colored[it]==col)
          return false;
      }
      return true;
  }
  bool canColor(int node,vector<vector<int>>& adj, int v, int m, vector<int>& colored)
  {
      if(node==v)
      return true;
      
      for(int col=1;col<=m;col++)
      {
          if(isSafe(node,col,adj,colored,v))
          {
              colored[node]=col;
              if(canColor(node+1,adj,v,m,colored))
              return true;
              colored[node]=0;
          }
      }
      return false;
  }
    bool graphColoring(int v, vector<vector<int>> &edges, int m)
    {
        // code here
        
        vector<vector<int>>adj(v);
        for(auto it: edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>colored(v,0);
        if(canColor(0,adj,v,m,colored))
        return true;
        return false;
    }
