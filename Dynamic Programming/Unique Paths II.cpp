class Solution {
public:
long long helper(vector<vector<int>>arr, int rows, int cols, vector<vector<int>>& dp)
{
    if(rows<0 || cols<0)
    return 0;
    // if(arr[rows][cols]==1)
    // return -1;

    if(arr[rows][cols]==1)
    return 0;

    if(rows==0 && cols==0)
    return 1;

    if(dp[rows][cols]!=-1)
    return dp[rows][cols];


    int upWay=helper(arr,rows-1,cols,dp);
    int leftWay=helper(arr,rows,cols-1,dp);
   
    return dp[rows][cols]=upWay+leftWay;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        // int m=obstacleGrid.size();
        // int n=obstacleGrid[0].size();
        // vector<vector<int>>dp(m, vector<int>(n,-1));
        // int ans= helper(obstacleGrid,m-1,n-1,dp);
        // if(ans==-1)
        // return 0;
        // else
        // return ans;

        //Tabulation Approach
          int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        //If Starting Point Itself An Obstacle Then Return 0 Ways
        if(obstacleGrid[0][0]==1)
        return 0;
        vector<vector<int>>dp(m, vector<int>(n,0));
        dp[0][0]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                //Dont Use i==0 || j==0
                //Since There Can Be An Obstacle In 0th row Or 0th Column
                if(i==0 && j==0 )
                continue;
                else if(obstacleGrid[i][j]==1)
                dp[i][j]=0;
                else
                {
                    int upWay=0;
                    int leftWay=0;
                    if(i>0)
                     upWay=dp[i-1][j];
                     if(j>0)
                     leftWay=dp[i][j-1];
                    dp[i][j]=upWay+leftWay;
                }
            }
        }
        return dp[m-1][n-1];
    }
};


