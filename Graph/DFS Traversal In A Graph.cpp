
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int start,vector<vector<int>>& adj, vector<int>& ans, vector<bool>& visited)
    {
        // ans.push_back()
        visited[start]=true;
        ans.push_back(start);
        
        //Traverse All Its Neighbours
        for(auto ele : adj[start])
        {
            if(!visited[ele])
            {
                dfs(ele,adj,ans,visited);
            }
        }
    }
    vector<int> dfsOfGraph(vector<vector<int>>& adj) 
    {
        // Code here
        vector<int>ans;
        vector<bool>visited(adj.size(),false);
        int start=0;
        dfs(start,adj,ans,visited);
        return ans;
    }
