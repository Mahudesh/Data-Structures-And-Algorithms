// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    queue<int>q;
   while(n--)
   {
       int val;
       cin>>val;
       q.push(val);
   }
   int size=1;
   double sum=q.front();
   cout<<fixed<<setprecision(2)<<sum<<" ";
   q.pop();
   while(q.size()>=1)
   {
       
       int b=q.front();
       q.pop();
       size++;
       sum=sum+b;
       double avg=(sum)/size;
       cout<<fixed<<setprecision(2)<<avg<<" ";
   }
}
