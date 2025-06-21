class Solution {
public:
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
class DisJointSet
{
    public:
    vector<int>parent,size;
    DisJointSet(int n)
    {
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
    int findParent(int node)
    {
        if(parent[node]==node)
        return node;

        return parent[node]=findParent(parent[node]);
    }
    void findUnionBySize(int u, int v)
    {
        int ult_u=findParent(u);
        int ult_v=findParent(v);
        if(ult_u==ult_v)
        return;

        if(size[ult_u]>size[ult_v])
        {
            parent[ult_v]=ult_u;
            size[ult_u]+=size[ult_v];
        }
        else
        {
            parent[ult_u]=ult_v;
            size[ult_v]+=size[ult_u];
        }
    }
};
// void dfs(int r, int c, vector<vector<bool>>& visited, vector<vector<int>>& grid, int& area)
// {
//     visited[r][c]=true;
//     for(int d=0;d<4;d++)
//     {
//         int nxtrow=r+dx[d];
//         int nxtcol=c+dy[d];
//         if(nxtrow>=0 && nxtcol>=0 && nxtrow<grid.size() && nxtcol<grid[0].size() && !visited[nxtrow][nxtcol] && grid[nxtrow][nxtcol]==1)
//         {
//             area++;
//             dfs(nxtrow,nxtcol,visited,grid,area);
//         }
//     }
// }
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        DisJointSet ds(n*m);
        bool f=false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                continue;

                f=true;
                for(int d=0;d<4;d++)
                {
                    int nxtrow=i+dx[d];
                    int nxtcol=j+dy[d];
                    if(nxtrow>=0 && nxtcol>=0 && nxtrow<n && nxtcol<m && grid[nxtrow][nxtcol]==1)
                    {
                        int node=(i*m)+j;
                        int adjnode=(nxtrow*m)+nxtcol;
                        if(ds.findParent(node)!=ds.findParent(adjnode))
                        {
                            ds.findUnionBySize(node,adjnode);
                        }
                    }
                }
            }
        }
        if(!f)
        return 0;
        int maxArea=0;
        for(int i=0;i<ds.parent.size();i++)
        {
            if(ds.parent[i]==i)
            maxArea=max(maxArea,ds.size[ds.parent[i]]);
        }
        return maxArea;
    }
};
