void topoSort(int start, vector<vector<pair<int,int>>>& adj, stack<int>& st, vector<bool>& visited)
{
    visited[start]=true;

    for(auto adjacent : adj[start])
    {

        if(!visited[adjacent.first])
        topoSort(adjacent.first,adj,st,visited);
    }
    st.push(start);
}
vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<pair<int,int>>>adj(n);
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];
        adj[u].push_back({v,wt});
    }
    stack<int>st;
    vector<bool>visited(n,false);
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
              topoSort(i,adj,st,visited);
        }
    }
    vector<int>dist(n,1e9);
    dist[0]=0;
    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        for(auto todo : adj[node])
        {
            int adjnode=todo.first;
            int newDist=todo.second;
            int d=dist[node];
            dist[adjnode]=min(dist[adjnode],d+newDist);

        }
    }
   for(int i=0;i<dist.size();i++)
   {
       if(dist[i]==1e9)
       dist[i]=-1;
   }
    
    return dist;
  
}
