class Solution {
public:
void dfs(int start, vector<bool>& visited, vector<vector<int>>& adj, int& edge, int& node)
{
    visited[start]=true;
    node++;
    for(auto it : adj[start])
    {
        edge++;
        if(!visited[it])
        dfs(it,visited,adj,edge,node);
    }
}
    int countCompleteComponents(int n, vector<vector<int>>& edges)
     {
        vector<bool>visited(n,false);
        // vector<int>adj[n];
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                int edge=0;
                int node=0;
                dfs(i,visited,adj,edge,node);
                edge=edge/2;

                //Formula For Finding Complete Connected Components
                if(edge == (node*(node-1))/2)
                cnt++;
            }
        }
        return cnt;
    }
};
