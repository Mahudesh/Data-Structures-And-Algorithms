class DisjointSet
{
    public:
    vector<int>size,parent;
    
    DisjointSet(int n)
    {
        size.resize(n);
        parent.resize(n);
        for(int i=0;i<=n;i++)
        {
            size[i]=1;
            parent[i]=i;
        }
    }
    
    int findParent(int node)
    {
        if(parent[node]==node)
        return node;
        
        return parent[node]=findParent(parent[node]);
    }
    void UnionBySize(int u, int v)
    {
        int ult_u=findParent(u);
        int ult_v=findParent(v);
        if(ult_u==ult_v)
        return;
        
        if(size[ult_v]<size[ult_u])
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
class Solution {
  public:
  bool isValid(int r,int c, int n, int m)
  {
      return r>=0&&c>=0 && r<n && c<m;
  }
  int dx[4]={1,-1,0,0};
  int dy[4]={0,0,1,-1};
    int largestIsland(vector<vector<int>>& grid)
    {
        // Your code goes here.
        
        
        int n=grid.size();
        int m=grid[0].size();
        DisjointSet ds(n*m);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    for(int d=0;d<4;d++)
                    {
                        int nxtrow=i+dx[d];
                        int nxtcol=j+dy[d];
                        
                        if(isValid(nxtrow,nxtcol,n,m) && grid[nxtrow][nxtcol]==1)
                        {
                            int node=(i*m)+j;
                            int adjnode=(nxtrow*m)+nxtcol;
                            if(ds.findParent(node)!=ds.findParent(adjnode))
                            ds.UnionBySize(node,adjnode);
                        }
                    }
                }
            }
        }
        int maxarea=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                unordered_set<int>st;
                if(grid[i][j]==0)
                {
                    for(int d=0;d<4;d++)
                    {
                        int nxtrow=i+dx[d];
                        int nxtcol=j+dy[d];
                        
                        if(isValid(nxtrow,nxtcol,n,m) && grid[nxtrow][nxtcol]==1)
                        {
                            int node=(i*m)+j;
                            int adjnode=(nxtrow*m)+nxtcol;
                            
                            int ult_parent=ds.findParent(adjnode);
                            
                            if(ds.findParent(node)!=ds.findParent(adjnode))
                            {
                                // area=area+ds.size[ult_parent]+1;
                                st.insert(ult_parent);
                            }
                        }
                    }
                    int area=0;
                    for(auto it : st)
                    {
                        area=area+ds.size[it];
                    }
                    maxarea=max(maxarea,area+1);
                    
                }
            }
        }
        if(maxarea==INT_MIN)
        return n*m;
        return maxarea;
        
    }
