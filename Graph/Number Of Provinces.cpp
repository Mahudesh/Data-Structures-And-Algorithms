class Solution {
public:
void dfs(int start, vector<vector<int>>& adj, vector<bool>& visited)
{
    visited[start]=true;
    for(auto it: adj[start])
    {
        if(!visited[it])
        {
            dfs(it,adj,visited);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected)
     {
        int n=isConnected.size();
        vector<vector<int>>adj(n+1);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    //Convert To 1-Based Indexing Of All Provinces(If Needed)
                    int u=i+1;
                    int v=j+1;
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }
        int cnt=0;
        vector<bool>visited(n+1,false);
        for(int i=1;i<=n;i++)
        {
            if(!visited[i])
            {
                cnt++;
                dfs(i,adj,visited);
            }
        }
        return cnt;
    }
};
// 1 1 0
// 1 1 0
// 0 0 1
