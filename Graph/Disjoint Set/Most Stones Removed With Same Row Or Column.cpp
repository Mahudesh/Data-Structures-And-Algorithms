class DisjointSet
{
    public:
    vector<int>size,parent;
    DisjointSet(int n)
    {
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        parent[i]=i;
    }

    int findParent(int node)
    {
        if(node==parent[node])
        return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ult_u=findParent(u);
        int ult_v=findParent(v);
        if(ult_u==ult_v)
        return;

        if(size[ult_u]>size[ult_v])
        {
            parent[ult_v]=ult_u;
            size[ult_u]=size[ult_u]+size[ult_v];
        }
        else
        {
            parent[ult_u]=ult_v;
            size[ult_v]=size[ult_v]+size[ult_u];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) 
    {
        int row=0;
        int col=0;
        //Given Coordinates Only So I Dont Know The Grid Size
        //So Take Row And Col As Maximum Of The Given Coordinates
        for(int i=0;i<stones.size();i++)
        {
            row=max(row,stones[i][0]);
            col=max(col,stones[i][1]);
        }
        DisjointSet ds(row+col+1);
        for(int i=0;i<stones.size();i++)
        {
            int node=stones[i][0];
            int adjnode=stones[i][1]+row+1;
            ds.unionBySize(node,adjnode);
        }
        int n=stones.size();
        int comp=0;
        //Find All Components
        //It Can Be Component If And Only It Has Super Boss Itself And Size Is Greater Than 1
        //If Super Boss Is Himself And Size Is 1 Then No Number Of Stones Are There
        //So Dont Take That
        for(int i=0;i<ds.parent.size();i++)
        {
            if(ds.parent[i]==i && ds.size[i]>1)
            comp++;
        }
        return n-comp;
    }
};
