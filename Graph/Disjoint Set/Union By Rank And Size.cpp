// #include<bits/stdc++.h>
// using namespace std;

        // Union By Rank
        
// class DisjointSet
// {
//     vector<int>rank,parent;
//     public:
//     DisjointSet(int n)
//     {
//         rank.resize(n+1,0);
//         parent.resize(n+1);
//         for(int i=0;i<=n;i++)
//         parent[i]=i;
//     }
    
//     int findParent(int node)
//     {
//         if(parent[node]==node)
//         return node;
        
//         return parent[node] = findParent(parent[node]);
//     }
    
//     void UnionByRank(int u, int v)
//     {
//         int ult_u = findParent(u);
//         int ult_v = findParent(v);
//         if(ult_u==ult_v)
//         return;
        
//         if(rank[ult_u]<rank[ult_v])
//         {
//             parent[ult_u]=ult_v;
//         }
//         else if(rank[ult_v]<rank[ult_u])
//         {
//             parent[ult_v]=ult_u;
//         }
//         else
//         {
//             parent[ult_u]=ult_v;
//             rank[ult_v]++;
//         }
//     }
// };

// int main()
// {
//     DisjointSet ds(7);
//     ds.UnionByRank(1,2);
//     ds.UnionByRank(2,3);
//     ds.UnionByRank(4,5);
//     ds.UnionByRank(6,7);
//     ds.UnionByRank(5,6);
    
//     if(ds.findParent(3) == ds.findParent(7))
//     cout<<"Same"<<endl;
//     else
//     cout<<"Not Same"<<endl;
//     ds.UnionByRank(3,7);
      
//     if(ds.findParent(3) == ds.findParent(7))
//     cout<<"Same"<<endl;
//     else
//     cout<<"Not Same"<<endl;
    
// }

        // Union By Size
#include<bits/stdc++.h>
using namespace std;
class DisjointSet
{
    vector<int>size,parent;
    public:
    DisjointSet(int n)
    {
        size.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
        parent[i]=i;
        size[i]=1;
        }
    }
    
    int findParent(int node)
    {
        if(parent[node]==node)
        return node;
        
        return parent[node] = findParent(parent[node]);
    }
    
    void findUnionBySize(int u, int v)
    {
        int ult_u=findParent(u);
        int ult_v=findParent(v);

        if(ult_u==ult_v)
        return;

        if(size[ult_u]<size[ult_v])
        {
            parent[ult_u]=ult_v;
            size[ult_v]+=size[ult_u];
        }
        else
        {
            parent[ult_v]=ult_u;
            size[ult_u]+=size[ult_v];
        }
    }
};

int main()
{
    DisjointSet ds(7);
    ds.UnionByRank(1,2);
    ds.UnionByRank(2,3);
    ds.UnionByRank(4,5);
    ds.UnionByRank(6,7);
    ds.UnionByRank(5,6);
    
    if(ds.findParent(3) == ds.findParent(7))
    cout<<"Same"<<endl;
    else
    cout<<"Not Same"<<endl;
    ds.UnionByRank(3,7);
      
    if(ds.findParent(3) == ds.findParent(7))
    cout<<"Same"<<endl;
    else
    cout<<"Not Same"<<endl;
    
}
