//Using Set
#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
 {
    // Write your code here.
    vector<vector<pair<int,int>>>adj(vertices);
    for(int i=0;i<edges;i++)
    {
        int u=vec[i][0];
        int v=vec[i][1];
        int wt=vec[i][2];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    set<pair<int,int>>st;
    st.insert({0,source});
    vector<int>dist(vertices,INT_MAX);
    dist[source]=0;
    while(!st.empty())
    {
        auto todo=*(st.begin());
        st.erase(todo);

        int dis=todo.first;
        int node=todo.second;

        for(auto adjacent : adj[node])
        {
            int adjNode=adjacent.first;
            int edgeWeight=adjacent.second;
            if(dis+edgeWeight<dist[adjNode])
            {
                //erase if it is existed
                //also it is the larger distance when compared 
                if(dist[adjNode]!=1e9)
                st.erase({dist[adjNode],adjNode});

                dist[adjNode]=dis+edgeWeight;
                st.insert({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}


//Using Priority Queue
Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
    {
        // Code here
        int n=adj.size();
        vector<int>dist(n,1e9);
        dist[src]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,src});
        while(!pq.empty())
        {
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto adjacent : adj[node])
            {
                int adjNode=adjacent.first;
                int edgeWeight=adjacent.second;
                if(dis+edgeWeight<dist[adjNode])
                {
                    dist[adjNode]=dis+edgeWeight;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
    }
};
