#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<pair<pair<int,int>,int>> ans;

    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=0;i<m;i++)
    {
        int u=g[i].first.first;
        int v=g[i].first.second;
        int wt=g[i].second;

        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
    // pq.push({})

    //wt,u,parent
    pq.push({0,{1,-1}});

    vector<bool>visited(n+1,false);
    while(!pq.empty())
    {
        auto todo=pq.top();
        pq.pop();
        int currwt=todo.first;
        int node=todo.second.first;
        int parent=todo.second.second;

        //If Visited Then It Can Be Already A Part Of The MST
        if(visited[node])
        continue;

        visited[node]=1;
        if(parent!=-1)
        ans.push_back({{node,parent},currwt});

        for(auto adjacent : adj[node])
        {
            int adjNode=adjacent.first;
            int edgeWt=adjacent.second;

            if(!visited[adjNode])
            pq.push({edgeWt,{adjNode,node}});
        }
    }
    return ans;
}
