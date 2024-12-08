class Solution {
public:
int helper(vector<vector<int>>matrix, int rows, int cols,vector<vector<int>>& dp)
{
    if(cols<0 || cols==matrix[0].size())
    return 1e9+7;
    if(rows==0)
    {
        return matrix[rows][cols];
    }
    if(dp[rows][cols]!=-1)
    return dp[rows][cols];

    int upper=matrix[rows][cols]+helper(matrix,rows-1,cols,dp);
    int leftDiagonal=matrix[rows][cols]+helper(matrix,rows-1,cols-1,dp);
    int rightDiagonal=matrix[rows][cols]+helper(matrix,rows-1,cols+1,dp);

    return dp[rows][cols]=min(upper,min(leftDiagonal,rightDiagonal));

}
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        // int rows=matrix.size();
        // int cols=matrix[0].size();
        // int maxi=INT_MAX;
        // for(int j=0;j<cols;j++)
        // {
        //     vector<vector<int>>dp(rows, vector<int>(cols,-1));
        //     int ans=helper(matrix,rows-1,j,dp);
        //     maxi=min(maxi,ans);
        // }
        // return maxi;
        //Tabulation Approach
        //Bottom Up Approach
    //     int rows=matrix.size();
    //     int cols=matrix[0].size();
    //    int mini=INT_MAX;
    //          vector<vector<int>>dp(rows,vector<int>(cols,0));
    //          for(int firstRow=0;firstRow<cols;firstRow++)
    //          {
    //             dp[0][firstRow]=matrix[0][firstRow];
    //          }
    //          for(int r=1;r<rows;r++)
    //          {
    //             for(int c=0;c<cols;c++)
    //             {

    //                 int upper=matrix[r][c]+dp[r-1][c];
    //                 int leftDiagonal=0,rightDiagonal=0;
    //                 if(c==0)
    //                 leftDiagonal=1e9+7;
    //                 else
    //                 leftDiagonal=matrix[r][c]+dp[r-1][c-1];

    //                 if(c==cols-1)
    //                 rightDiagonal=1e9+7;
    //                 else
    //                  rightDiagonal=matrix[r][c]+dp[r-1][c+1];

    //                 dp[r][c]=min(upper,min(leftDiagonal,rightDiagonal));
    //             }
    //          }
    //          //Since In Recursion All The Possible Ways Starting From rows-1 Is Calculated
    //          //And Finally It Has Taken Minimum All Of That
    //          //Here Also In Single Pass dp Will Contain All Solutions Of n-1 At dp[rows-1]
    //          for(int j=0;j<cols;j++)
    //          {
    //             mini=min(mini,dp[rows-1][j]);
    //          }
        
    //     return mini;

        //Space Optimization
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<int>prev(cols,0);
        for(int j=0;j<cols;j++)
        {
            prev[j]=matrix[0][j];
        }
        for(int r=1;r<rows;r++)
        {
            vector<int>dummyDp(cols,0);
            for(int c=0;c<cols;c++)
            {
                int upper=matrix[r][c]+prev[c];
                int leftDiagonal=0,rightDiagonal=0;
                if(c==0)
                leftDiagonal=1e9+7;
                else
                leftDiagonal=matrix[r][c]+prev[c-1];
                if(c==cols-1)
                rightDiagonal=1e9+7;
                else
                rightDiagonal=matrix[r][c]+prev[c+1];
                dummyDp[c]=min(upper,min(leftDiagonal,rightDiagonal));
            }
            prev=dummyDp;
        }
        int mini=INT_MAX;
        for(int j=0;j<cols;j++)
        {
            mini=min(mini,prev[j]);
        }
        return mini;
    }
};
