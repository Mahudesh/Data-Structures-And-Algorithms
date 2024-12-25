#include <algorithm>

class Kthlargest {
public:
int K;
priority_queue<int, vector<int>, greater<int>>q;
    Kthlargest(int k, vector<int> &arr)
     {
         K=k;

         for(int i=0;i<min(k,(int)arr.size());i++)
         {
             q.push(arr[i]);
         }
         for(int i=k;i<arr.size();i++)
         {
             if(arr[i]>q.top())
             {
                 q.pop();
                 q.push(arr[i]);
             }
         }
    }

    int add(int num)
     {
         if(q.size()<K)
         q.push(num);
         else if(num>q.top())
         {
             q.pop();
             q.push(num);
         }
         return q.top();
    }

};
