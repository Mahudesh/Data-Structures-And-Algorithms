class Solution {
public:
// bool isMin(int n, int m, vector<vector<int>>& matrix, int ele, int rowIndex)
// {
//     for(int j=0;j<m;j++)
//     {
//         if(ele>matrix[rowIndex][j])
//         return false;
//     }
//     return true;
// }
    vector<int> luckyNumbers(vector<vector<int>>& matrix) 
    {
        
        vector<int>ans;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>rowMin(n,INT_MAX);
        vector<int>colMax(m,INT_MIN);


        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                rowMin[i]=min(rowMin[i],matrix[i][j]);
                colMax[j]=max(colMax[j],matrix[i][j]);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==rowMin[i] && colMax[j]==matrix[i][j])
                ans.push_back(matrix[i][j]);
            }
        }
        // for(int j=0;j<m;j++)
        // {
        //     int rowIndex=-1;
        //     int maxi=INT_MIN;
        //     for(int i=0;i<n;i++)
        //     {
        //         if(maxi<matrix[i][j])
        //         {
        //             maxi=matrix[i][j];
        //             rowIndex=i;
        //         }
        //     }
        //     if(isMin(n,m,matrix,maxi,rowIndex))
        //     ans.push_back(maxi);
        // }
        return ans;
    }
};
// 3 7 8
// 9 11 13
// 15 16 17
