private:
    void dfs(int start, vector<vector<int>>& adj, vector<bool>& visited,stack<int> &st)
    {
        visited[start]=true;
        
        for(auto adjacent : adj[start])
        {
            if(!visited[adjacent])
            dfs(adjacent,adj,visited,st);
        }
        st.push(start);
    }
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) 
    {
        // Your code here
        
        //DFS
        vector<int>ans;
        int n=adj.size();
        vector<bool>visited(n,false);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i,adj,visited,st);
            }
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
