#include<queue>
// bool isCycle(int start,vector<vector<int>>& adj,vector<bool>& visited)
// {
//     queue<pair<int,int>>q;
//     q.push({start,-1});
//     visited[start]=true;
//     // vector<bool>visited(n+1,false);
//     while(!q.empty())
//     {
//         auto todo=q.front();
//         q.pop();
//         int node=todo.first;
//         int parent=todo.second;

//         for(auto ele : adj[node])
//         {
//             if(!visited[ele])
//             {
//                 visited[ele]=true;
//                 q.push({ele,node});
//             }
//             else if(visited[ele]==true)
//             {
//                 //If I Found A Visited Person But He Is Not His Parent
//                 if(ele!=parent)
//                 return true;
//             }
//         }
//     }
//     return false;
// }
bool isCycle(int start, int parent,vector<vector<int>>& adj, vector<bool>& visited)
{
    visited[start]=true;
    bool f=false;
    for(auto ele : adj[start])
    {
        if(!visited[ele])
        {
            //If My Any Of The Calls Got True Then Return True For All Remaining Calls
           if(isCycle(ele,start,adj,visited))
           return true;
        }
        else if(visited[ele])
        {
            //If I Found A Visited Person But He Is Not His Parent
            if(ele!=parent)
            return true;
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
     vector<vector<int>>adj(n+1);
     vector<bool>visited(n+1,false);
    for(int i=0;i<m;i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            if(isCycle(i,-1,adj,visited))
            return "Yes";
        }
    }
    return "No";

}
