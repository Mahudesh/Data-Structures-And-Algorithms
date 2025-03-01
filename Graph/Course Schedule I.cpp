#include <bits/stdc++.h> 
string canFinish(vector<vector<int>>& prerequisites, int n, int m)
{
    if(prerequisites.size()==0 || m==0 || n==0)
    return "Yes";
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++)
    {
        int u=prerequisites[i][0];
        int v=prerequisites[i][1];
        adj[u].push_back(v);
    }
    // vector<int>topoSort;
    int topoElements=0;
    queue<int>q;
    vector<int>inDegree(n+1,0);
    for(int i=1;i<=n;i++)
    {
        for(auto ele : adj[i])
        {
            inDegree[ele]++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(inDegree[i]==0)
        q.push(i);
    }

    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        topoElements++;

        for(auto adjacent : adj[node])
        {
            inDegree[adjacent]--;
            if(inDegree[adjacent]==0)
            q.push(adjacent);
        }
    }
    if(topoElements==n)
    return "Yes";
    return "No";
}
