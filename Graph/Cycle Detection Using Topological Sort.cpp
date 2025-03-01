 bool isCyclic(vector<vector<int>> &adj)
    {
        // code here
        //Using Topological Sort (BFS)
        queue<int>q;
        int n=adj.size();
        vector<int>inDegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto ele : adj[i])
            inDegree[ele]++;
        }
        
        for(int i=0;i<n;i++)
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
            
            for(auto adjacent : adj[node])
            {
                inDegree[adjacent]--;
                if(inDegree[adjacent]==0)
                q.push(adjacent);
            }
        }
        
        return topoSort.size()!=n;
    }
