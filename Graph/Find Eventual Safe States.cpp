class Solution {
public:
bool dfs(int start, vector<bool>& visited, vector<bool>& pathVisited, vector<vector<int>>& adj)
{
    visited[start]=true;
    pathVisited[start]=true;

    for(auto adjacent : adj[start])
    {
        if(!visited[adjacent])
        {
            if(dfs(adjacent,visited,pathVisited,adj))
            return true;
        }
        else if(visited[adjacent])
        {
            if(pathVisited[adjacent]==true)
            return true;
        }
       
    }
    pathVisited[start]=false;
    return false;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        vector<int>ans;
        int n=graph.size();
        vector<bool>visited(n,false);
        vector<bool>pathVisited(n,false);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i,visited,pathVisited,graph);
            }
        }
        for(int i=0;i<pathVisited.size();i++)
        {
            //If Path Is Not Visited Then It Does Not Contains Cycle
            //Coz If I Dont Find A Cycle In A Node I Reset Its Path In BackTracking
            if(pathVisited[i]==0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
