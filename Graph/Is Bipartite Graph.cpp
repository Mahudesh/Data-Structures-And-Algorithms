class Solution {
public:
bool Check(int start,vector<vector<int>>& adj, vector<int>& colored)
{
        queue<int>q;
        q.push(start);
        colored[start]=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();

            for(auto adjacent : adj[node])
            {
                if(colored[adjacent]==-1)
                {
                    //If Adjacent Is Not Colored Then Color It With Opposite Color Of Current Node 
                    colored[adjacent]=!colored[node];
                    q.push(adjacent);
                }
                else if(colored[adjacent]!=-1)
                {
                    //If Adjacent Is Colored Then Both Adjacent And Current Dont Have Same Color
                    if(colored[adjacent]==colored[node])
                    return false;
                }
            }
        }
        return true;
}
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        int m=graph[0].size();
        vector<int>colored(n,-1);
        for(int i=0;i<n;i++)
        {
            if(colored[i]==-1)
            {
                if(!Check(i,graph,colored))
                return false;
            }
        }
       
        return true;
    }
};
// 1 2 3
// 0 
