class Solution {
  public:
    // Function to find a solved Sudoku.
    bool isSafe(int row, int col,int num,vector<vector<int>>& mat)
    {
        for(int i=0;i<9;i++)
        {
            if(mat[i][col]==num || mat[row][i]==num)
            return false;
        }
        int nxtrow=row-(row%3);
        int nxtcol=col-(col%3);
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(mat[i+nxtrow][j+nxtcol]==num)
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<int>>& mat)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(mat[i][j]==0)
                {
                    for(int num=1;num<=9;num++)
                    {
                        if(isSafe(i,j,num,mat))
                        {
                            mat[i][j]=num;
                            if(solve(mat))
                            return true;
                            mat[i][j]=0;
                        }
                    }
                    return false;
                }
                
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<int>> &mat)
    {
        // code here
        solve(mat);
        
    }
};
