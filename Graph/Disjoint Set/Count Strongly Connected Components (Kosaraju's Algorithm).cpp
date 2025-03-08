#include<bits/stdc++.h>
void dfs(int start,int v, vector<bool>& visited, vector<vector<int>>& adj, stack<int>& st)
{
	visited[start]=true;

	for(auto adjacent : adj[start])
	{
		if(!visited[adjacent])
		dfs(adjacent,v,visited,adj,st);
	}
	st.push(start);
}
void dfs2(int start,vector<bool>& visited, vector<vector<int>>& adj)
{
	visited[start]=true;

	for(auto it : adj[start])
	{
		if(!visited[it])
		dfs2(it,visited,adj);
	}
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// Write your code here.
	stack<int>st;
	vector<vector<int>>adj(v);
	for(int i=0;i<edges.size();i++)
	{
		int u=edges[i][0];
		int v=edges[i][1];
		adj[u].push_back(v);
	}
	vector<bool>visited(v,false);

	//Run Loop For All Vertices
	//Since There Can Be Disconnected Components As Well
	for(int i=0;i<v;i++)
	{
		if(!visited[i])
		dfs(i,v,visited,adj,st);

	}

	vector<vector<int>>adjRev(v);
	for(int i=0;i<v;i++)
	{
		for(auto adjacent : adj[i])
		{
			adjRev[adjacent].push_back(i);
		}
	}
	fill(visited.begin(),visited.end(),false);
	int cnt=0;
	while(!st.empty())
	{
		int node=st.top();
		st.pop();
		if(!visited[node])
		{
			cnt++;
			dfs2(node,visited,adjRev);
		}
	}
	return cnt;
}
