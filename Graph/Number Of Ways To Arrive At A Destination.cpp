class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<roads.size();i++)
        {
            int u=roads[i][0];
            int v=roads[i][1];
            int wt=roads[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>>pq;
        vector<long long>dist(n,LLONG_MAX);
        int mod=1e9+7;
        vector<int>ways(n,0);
        ways[0]=1;
        dist[0]=0;
        pq.push({0,0});
        while(!pq.empty())
        {
            auto todo=pq.top();
            pq.pop();
            long long dis=todo.first;
            long long node=todo.second;

            for(auto adjacent : adj[node])
            {
                int adjNode=adjacent.first;
                int edgeWt=adjacent.second;

                if(dis+edgeWt<dist[adjNode])
                {
                    dist[adjNode]=dis+edgeWt;
                    pq.push({dis+edgeWt,adjNode});
                    ways[adjNode]=ways[node];
                }
                else if(dis+edgeWt==dist[adjNode])
                {
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};
