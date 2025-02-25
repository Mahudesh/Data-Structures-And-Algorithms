class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        int cntFresh=0;

        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>visited(n, vector<int>(m,0));
        //Initially Put All Oranges Rotten Into The Queue And Mark As Visited
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    visited[i][j]=2;    
                }
                if(grid[i][j]==1)
                cntFresh++;
            }
        }

        int maxTimer=0;
        int changeRow[8]={1,-1,0,0};
        int changeCol[8]={0,0,-1,1};


        while(!q.empty())
        {
            auto todo=q.front();
            q.pop();

            int i=todo.first.first;
            int j=todo.first.second;
            int timer=todo.second;
            //Update Whatever The Maximum Time Taken We Get
            maxTimer=max(maxTimer,timer);
            for(int d=0;d<4;d++)
            {
                int nxtRow=i+changeRow[d];
                int nxtCol=j+changeCol[d];
                //Last 2 Conditions
                //Check Whether The Next Coordinate Contains Fresh Oranges
                //Check Whether The Next Coordinate Is Unvisited Which Means It Is Not Already Rotton
                if(nxtRow>=0 && nxtRow<n && nxtCol>=0 && nxtCol<m && grid[nxtRow][nxtCol]==1 && visited[nxtRow][nxtCol]!=2)
                {
                    q.push({{nxtRow,nxtCol},timer+1});
                    visited[nxtRow][nxtCol]=2;
                    cntFresh--;
                }
            }
        }
        
            if(cntFresh==0)
            return maxTimer;
            return -1;
    }
};
