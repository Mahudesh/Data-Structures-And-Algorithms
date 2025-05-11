Solution {
  public:
    int kthLargest(vector<int> &arr, int k)
    {
        // code here
           priority_queue<int, vector<int>,greater<int>>pq;
        //   int sum=0;
           for(int i=0;i<arr.size();i++)
           {
               int sum=0;
               for(int j=i;j<arr.size();j++)
               {
                   sum+=arr[j];
                   
                pq.push(sum);
                if(pq.size()>k)
                pq.pop();
                //   if(pq.size()<k)
                //   pq.push(sum);
                //   else
                //   {
                //       if(pq.top()<sum)
                //       {
                //           pq.pop();
                //           pq.push(sum);
                //       }
                //   }
               }
           }
           return pq.top();
           // 
    } // 1 2 3
};
