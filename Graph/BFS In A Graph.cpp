vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{
    // Write your code here.
    vector<bool>visited(n,false);
    vector<int>bfs;
    queue<int>q;
    q.push(0);
    visited[0]=true;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        visited[node]=true;
        bfs.push_back(node);
        for(auto ele : adj[node])
        {
            if(!visited[ele])
            {
                q.push(ele);
                visited[ele]=true;
            }
        }
    }
    return bfs;

}
