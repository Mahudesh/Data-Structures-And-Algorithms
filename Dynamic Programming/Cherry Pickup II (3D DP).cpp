class Solution {
public:
int helper(vector<vector<int>>grid, int rows, int cols1, int cols2, vector<vector<vector<int>>>& dp)
{
    if(cols1 < 0 || cols1==grid[0].size() || cols2<0 || cols2==grid[0].size())
    {
        return -(1e9);
    }
    //If Same Cell Reached By Two Robots Return One Of The Value
    //If Some Other Two Distinct Cell Reached By Two Robots Return Both Of The Value
    if(rows==grid.size()-1)
    {
        if(cols1==cols2)
        {
            return grid[rows][cols1];
        }
        else
        {
            return grid[rows][cols1]+grid[rows][cols2];
        }
    }
    if(dp[rows][cols1][cols2]!=-1)
    return dp[rows][cols1][cols2];
    int maxCherry=0;
    //dcols1 Represents A Robot
    //dcols2 Represents B Robot
    //For Every Move Either(-1,0,1) Column Side Of A Robot
    //Will Have Corresponding Three Moves(-1,0,1) By B Robot
    //Total 3X3 Combos
    for(int dcols1=-1;dcols1<=1;dcols1++)
    {
        for(int dcols2=-1;dcols2<=1;dcols2++)
        {
            int sum=0;
         if(cols1==cols2)
        sum=sum+ grid[rows][cols1] +  helper(grid,rows+1,cols1+dcols1,cols2+dcols2,dp);
         else
        sum=sum+ grid[rows][cols1]+grid[rows][cols2]+helper(grid,rows+1,cols1+dcols1,cols2+dcols2,dp);

        maxCherry=max(maxCherry,sum);
        }
    }
    return dp[rows][cols1][cols2]=maxCherry;
}
    int cherryPickup(vector<vector<int>>& grid)
     {
        // int rows=grid.size();
        // int cols=grid[0].size();
        // vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols,-1)));
        // return helper(grid,0,0,cols-1,dp);

        //Tabulation Approach
        //Bottom Up Approach
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols,-1)));
        for(int j1=0;j1<cols;j1++)
        {
            for(int j2=0;j2<cols;j2++)
            {
                if(j1==j2)
                dp[rows-1][j1][j2]=grid[rows-1][j1];
                else
                dp[rows-1][j1][j2]=grid[rows-1][j1]+grid[rows-1][j2];
            }
        }
        for(int i=rows-2;i>=0;i--)
        {
            for(int j1=0;j1<cols;j1++)
            {
                for(int j2=0;j2<cols;j2++)
                {
                    int maxCherry=0;
                    for(int dcols1=-1;dcols1<=1;dcols1++)
                    {
                        for(int dcols2=-1;dcols2<=1;dcols2++)
                        {
                            int sum=0;
                            if(j1==j2)
                            {
                                if(j1+dcols1>=0 && j2+dcols2>=0 && j1+dcols1<cols && j2+dcols2<cols)
                                sum=sum+grid[i][j1]+dp[i+1][j1+dcols1][j2+dcols2];
                                else
                                sum=(-1e9);
                            }
                            else
                            {
                                 if(j1+dcols1>=0 && j2+dcols2>=0 && j1+dcols1<cols && j2+dcols2<cols)
                                sum=sum+grid[i][j1]+grid[i][j2]+dp[i+1][j1+dcols1][j2+dcols2];
                                 else
                                sum=(-1e9);
                            }
                           maxCherry=max(maxCherry,sum);
                        }
                    }
                    dp[i][j1][j2]=maxCherry;
                }
            }
        }
        return dp[0][0][cols-1];
    }
};
