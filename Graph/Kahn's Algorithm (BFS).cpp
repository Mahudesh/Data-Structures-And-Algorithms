#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) 
 {
    // Write your code here
    queue<int>q;
    vector<int>indegree(v,0);
    vector<vector<int>>adj(v);
    for(int i=0;i<e;i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    for(int i=0;i<v;i++)
    {
        for(auto ele : adj[i])
        indegree[ele]++;
    }

    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }
    vector<int>ans;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto ele : adj[node])
        {
            indegree[ele]--;
            if(indegree[ele]==0)
            q.push(ele);
        }
    }
    return ans;
}
