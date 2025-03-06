Solution {
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src)
    {
        // Code here
        vector<int>dist(V,1e8);
        dist[src]=0;
        for(int i=0;i<V-1;i++)
        {
            for(int i=0;i<edges.size();i++)
            {
                // for(int )
                int u=edges[i][0];
                int v=edges[i][1];
                int wt=edges[i][2];
                if(dist[u]!=1e8)
                {
                    if(dist[u]+wt < dist[v])
                    {
                        dist[v]=dist[u]+wt;
                    }
                }
            }
        }
        for(auto it : edges)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(dist[u]!=1e8 && dist[u]+wt < dist[v])
            return {-1};
        }
        return dist;
    }
