class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        priority_queue<int>pq;
        int n=matrix.size();
        int t=k;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                pq.push(matrix[i][j]);
                if(pq.size()>k)
                pq.pop();
            }
        }
        return pq.top();
    }
};
// 1 5 9
// 10 11 13
// 12 13 15
