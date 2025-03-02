class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int n=heights.size();
        int m=heights[0].size();

        //Priority Queue Which Stores Difference Distance And With Row Col To Be The Coordinates
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;

        pq.push({0,{0,0}});

        vector<vector<int>>dist(n, vector<int>(m,1e9));

        int dr[4]={0,0,1,-1};
        int dc[4]={1,-1,0,0};
        while(!pq.empty())
        {
            auto todo=pq.top();
            pq.pop();

            int diffdist=todo.first;
            int row=todo.second.first;
            int col=todo.second.second;

            if(row==n-1 && col==m-1)
            return diffdist;

            for(int d=0;d<4;d++)
            {
                int nxtRow=row+dr[d];
                int nxtCol=col+dc[d];
                if(nxtRow>=0 && nxtCol<m && nxtCol>=0 && nxtRow<n)
                {
                    //I Need Only The Minimum Effort Required To Destination
                    //But An Effort Is Defined As The Maximum Absolute Difference Of Any Two
                    //Consecutive Cells In Its Path
                    //So Update The Distance Effort Matrix If I Found A Lesser New Effort

                    int effortTaken=max(diffdist,abs(heights[row][col]-heights[nxtRow][nxtCol]));
                    if(dist[nxtRow][nxtCol]>effortTaken)
                    {
                        dist[nxtRow][nxtCol]=effortTaken;
                        pq.push({effortTaken,{nxtRow,nxtCol}});
                    }
                }
            }


        }
        return -1;
        
    }
};
