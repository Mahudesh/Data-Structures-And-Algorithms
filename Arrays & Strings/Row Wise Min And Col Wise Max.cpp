#include <bits/stdc++.h> 
vector <int> chuninNinja(int n , int m , vector < vector < int > > arr)
{
   // Write your code here.
   vector<int>ans;
   vector<int>rowMin(n,INT_MAX);
   vector<int>colMax(m,INT_MIN);
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<m;j++)
      {
         rowMin[i]=min(rowMin[i],arr[i][j]);
         colMax[j]=max(colMax[j],arr[i][j]);
      }
   }
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<m;j++)
      {
         if(arr[i][j]==rowMin[i] && arr[i][j]==colMax[j])
         ans.push_back(arr[i][j]);
      }
   }
   return ans;
}
// 3 4 5
// 2 7 6
// 1 2 4
