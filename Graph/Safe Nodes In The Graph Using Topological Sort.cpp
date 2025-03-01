#include <bits/stdc++.h> 
vector<int> safeNodes(vector<vector<int>> &edges, int n, int e) 
{
    // Write your code here.

    //BFS Technique Using Topological Sort
    vector<int>safenodes;

    //Reverse The Edges
    vector<vector<int>>adj(n);
      vector<int>inDegree(n,0);
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[v].push_back(u);
        inDegree[u]++;
    }

    queue<int>q;
   
    // for(int i=0;i<n;i++)
    // {
    //     for(auto ele : adj[i])
    //     inDegree[ele]++;
    // }

    for(int i=0;i<n;i++)
    {
        if(inDegree[i]==0)
        q.push(i);
    }
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        safenodes.push_back(node);
        for(auto ele : adj[node])
        {
            inDegree[ele]--;
            if(inDegree[ele]==0)
            q.push(ele);
        }
    }
    sort(safenodes.begin(),safenodes.end());
    return safenodes;
}
