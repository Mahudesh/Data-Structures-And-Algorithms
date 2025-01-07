int findRoot(int n, int mid,int m)
{
  //Return 0 if ans==m
  //Return 1 if ans<m
  //Return 2 if ans>m
  long long ans=1;
  for(int i=1;i<=n;i++)
  {
    ans=ans*mid;
    if(ans>m)
     return 2;
  }
  if(ans==m) 
  return 0;
  return 1;
}
int NthRoot(int n, int m)
 {
   int low=1;
   int high=m;
   while(low<=high)
   {
     int mid=(low+high)/2;
     int root=findRoot(n,mid,m);
     if(root==0) 
     {
       return mid;
     }
     else if(root==2)
     {
       high=mid-1;
     }
     else if(root==1)
     {
       low=mid+1;
     }
   }
   return -1;
}
