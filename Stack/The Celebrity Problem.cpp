Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat)
    {
        // code here
        // vector<int>iknow(mat.size());
        // vector<int>known(mat.size());
        // for(int i=0;i<mat.size();i++)
        // {
        //     for(int j=0;j<mat[i].size();j++)
        //     {
        //         if(mat[i][j]==1)
        //         {
        //             known[j]=known[j]+1;
        //             iknow[i]=iknow[i]+1;
        //         }
        //     }
        // }
        // for(int i=0;i<known.size();i++)
        // {
        //     if(known[i]==mat.size()-1 && iknow[i]==0)
        //     return i;
        // }
        // return -1;
        
        //Optimized
        int top=0;
        int bottom=mat.size()-1;
        
        while(top<bottom)
        {
            if(mat[top][bottom]==1)
            top++;
            else if(mat[bottom][top]==1)
            bottom--;
            else
            {
                top++;
                bottom--;
            }
        }
        if(top>bottom)
        return -1;
        for(int j=0;j<mat.size();j++)
        {
            if(top!=j)
            {
                if(mat[top][j]==0 && mat[j][top]==1)
                continue;
                else
                return -1;
            }
        }
        return top;
    }
};
