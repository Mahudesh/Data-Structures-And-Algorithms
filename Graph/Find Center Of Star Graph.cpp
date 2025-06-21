class Solution {
public:
    int findCenter(vector<vector<int>>& edges)
    {
        // If There Is A Centre Edge Then It Should Be In All The Edges
        // So Take Any Two Edges And Check Which Is The Common Node
        if(edges[0][0]==edges[1][0] || edges[0][0]==edges[1][1])
        return edges[0][0];
        return edges[0][1];
    }
};class Solution {
public:
    int findCenter(vector<vector<int>>& edges)
    {
        // If There Is A Centre Edge Then It Should Be In All The Edges
        // So Take Any Two Edges And Check Which Is The Common Node
        if(edges[0][0]==edges[1][0] || edges[0][0]==edges[1][1])
        return edges[0][0];
        return edges[0][1];
    }
};
