bool dfs(int start, vector<bool>& visited, vector<bool>& pathVisited, vector<vector<int>>& adj)
{
  visited[start]=true;

    pathVisited[start]=true;
  for(auto adjacent : adj[start])
  {
    //If The Node Is Not Visited Then Visit It
    if(!visited[adjacent])
    {
      if(dfs(adjacent,visited,pathVisited,adj)==true)
      return true;
    }
    else if(visited[adjacent])
    {
      //If The Node Is Visited Then It Has To Be In Same Path
      //In Same Path Means Path[adjacent] Must Be True To Be In Same Path
      //If So Then There Exits A Cycle
      if(pathVisited[adjacent]==true)
      return true;
    }
  }
  pathVisited[start]=false;
  return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) 
{
  // Write your code here.
  vector<vector<int>>adj(n+1);
  for(int i=0;i<edges.size();i++)
  {
    int u=edges[i].first;
    int v=edges[i].second;
    adj[u].push_back(v);
  }
  vector<bool>pathVisited(n+1,false);
  vector<bool>visited(n+1,false);

  for(int i=1;i<=n;i++)
  {
    if(!visited[i])
    {
      if(dfs(i,visited,pathVisited,adj))
      return 1;
    }
  }
  return 0;
}
