#include<vector>
#include<set>
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
void dfs(int row, int col, int** arr, vector<pair<int,int>>& vec, vector<vector<bool>>& visited, int baserow, int basecol, int n, int m)
{
    visited[row][col]=true;
    //Subtract From The Base Coordinate To Make Same Coordinate For All Duplicate Islands
    vec.push_back({row-baserow,col-basecol});

    for(int d=0;d<4;d++)
    {
        int nxtRow=row+dx[d];
        int nxtCol=col+dy[d];
        if(nxtRow>=0 && nxtCol>=0 && nxtCol<m && nxtRow<n && !visited[nxtRow][nxtCol] && arr[nxtRow][nxtCol]==1)
        {
            dfs(nxtRow,nxtCol,arr,vec,visited,baserow,basecol,n,m);
        }
    }


}
int distinctIslands(int** arr, int n, int m)
{
    //Write your code here
    set<vector<pair<int,int>>>st;
    vector<vector<bool>>visited(n, vector<bool>(m,false));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            //Vector Of Pairs For Storing All The Coordinates Of Current Island
            vector<pair<int,int>>vec;
            if(!visited[i][j]&& arr[i][j]==1)
            {
                dfs(i,j,arr,vec,visited,i,j,n,m);
                //Pushing Into The Set For Storing All Duplicate Coordinate Of Islands
               st.insert(vec);
            }
        }
    }
    return st.size();
}
