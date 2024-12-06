class Solution {
public:
int helper(int row, int col, vector<vector<int>>& dp)
{
    //Base Case
    if(row==0 && col==0)
    return 1;

    if(row<0 || col<0)
    return 0;
    if(dp[row][col]!=-1)
    return dp[row][col];

    int upWay=helper(row-1,col,dp);
    int leftWay=helper(row,col-1,dp);

    return dp[row][col]=upWay+leftWay;
}
    int uniquePaths(int m, int n) 
    {
        //Recursion
        //Top Down Approach
        //Memoization
        //Maximum Value Of i is m-1
        //Maximum Value Of j is n-1
        //To Get Rid Of Storing m-1 And n-1 Values I Need mxn 2D Matrix
        // vector<vector<int>>dp(m, vector<int>(n,-1));
        // return helper(m-1,n-1,dp);

        //Tabulation Approach
        //Bottom Up Approach

        // vector<vector<int>>dp(m, vector<int>(n,0));

        // dp[0][0]=1;
        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         if(i==0 && j==0)
        //         continue;
        //         //if(i==0 || j==0)
        //         //dp[i][j]=1;
        //         int upWay=0,leftWay=0;
        //         if(i>0)
        //          upWay=dp[i-1][j];
        //          if(j>0)
        //          leftWay=dp[i][j-1];
        //         dp[i][j]=upWay+leftWay;
        //         //dp[i][j]=dp[i-1][j]+dp[i][j-1]
        //     }
        // }
        // return dp[m-1][n-1];

        //Space Optimization
        vector<int>prev(n,0);
        for(int i=0;i<m;i++)
        {
            vector<int>dummyDp(n,0);
            for(int j=0;j<n;j++)
            {
                if(i==0 || j==0)
                dummyDp[j]=1;
                else
                {
                    //For Previous Row Take It From Prev Computed Row
                    //For Previous Column Take It From Previous Column Of dummyDp
                    dummyDp[j]=prev[j]+dummyDp[j-1];
                }

            }
            prev=dummyDp;
        }
        return prev[n-1];
    }
};
