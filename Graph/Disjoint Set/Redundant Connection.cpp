class Solution {
public:
class DisjointSet
{
    public:
    vector<int>parent,size;
    DisjointSet(int n)
    {
        parent.resize(n+1,0);
        size.resize(n+1,0);
        for(int i=0;i<=n;i++)
        parent[i]=i;
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        int n=edges.size();
        DisjointSet ds(n);
        for(auto it : edges)
        {
            int u=it[0];
            int v=it[1];
            if(ds.findParent(u)!=ds.findParent(v))
            {
                ds.findUnionBySize(u,v);
            }
            else
            {
                return {u,v};
            }
        }
        return {};
    }
};
