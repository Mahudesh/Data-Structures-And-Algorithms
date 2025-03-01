vector<int> findSchedule(int V, vector<pair<int, int>> &prerequisites)
{
    // Write your code here.
    vector<int>adj[V+1];
    queue<int>q;
    for(int i=0;i<prerequisites.size();i++)
    {
        int u=prerequisites[i].first;
        int v=prerequisites[i].second;
        adj[v].push_back(u);
    }
    vector<int>inDegree(V+1,0);
    for(int i=1;i<=V;i++)
    {
        for(auto ele : adj[i])
        {
            inDegree[ele]++;
        }
    }
    for(int i=1;i<=V;i++)
    {
        if(inDegree[i]==0)
        q.push(i);
    }
    vector<int>topoSort;
    while(!q.empty())
    {
        auto node=q.front();
        q.pop();
        topoSort.push_back(node);

        for(auto  adjacent : adj[node])
        {
            inDegree[adjacent]--;
            if(inDegree[adjacent]==0)
            q.push(adjacent);
        }

    }
    if(topoSort.size()!=V)
    return {};
    return topoSort;
 
}
