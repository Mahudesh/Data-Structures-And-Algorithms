class DisjointSet
{
    public:
    vector<int>parent,rank;
    DisjointSet(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<n;i++)
        parent[i]=i;
    }
    int findParent(int node)
    {
        if(node==parent[node])
        return node;

        return parent[node] = findParent(parent[node]);
    }

    void UnionFind(int u, int v)
    {
        int ult_u=findParent(u);
        int ult_v=findParent(v);

        if(ult_v==ult_u)
        return;

        if(rank[ult_u]<rank[ult_v])
        {
            parent[ult_u]=ult_v;
        }
        else if(rank[ult_v]<rank[ult_u])
        {
            parent[ult_v]=ult_u;
        }
        else
        {
            parent[ult_u]=ult_v;
            rank[ult_v]++;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        DisjointSet ds(n);

        int cntExtra=0;
        for(int i=0;i<connections.size();i++)
        {
            int u=connections[i][0];
            int v=connections[i][1];
            //If Already Connected Then It Is An Extra Edge
            //If Extra Edge Exists Then I Can Remove It
            if(ds.findParent(u)==ds.findParent(v))
            cntExtra++;
            else
            ds.UnionFind(u,v);
        }
        int cntBoss=0;
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i]==i)
            cntBoss++;
        }
        //For 5 Provinces I Need Only 4 Edges To Connect
        if(cntExtra>=cntBoss-1)
        return cntBoss-1;
        return -1;
    }
};
