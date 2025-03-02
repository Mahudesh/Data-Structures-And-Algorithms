
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<m;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        vector<int>dist(n+1,1e9);
        vector<int>parent(n+1);
        for(int i=1;i<=n;i++)
        parent[i]=i;
        
        pq.push({0,1});
        dist[1]=0;
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
                    parent[adjNode]=node;
                }
            }
        }
        if (dist[n] == 1e9) return {-1};  // Return -1 if node `n` is unreachable

        vector<int>ans;
        int node=n;
        while(parent[node]!=node)
        {
            ans.push_back(node);
            node=parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        ans.insert(ans.begin(),dist[n]);
        return ans;
        
        
