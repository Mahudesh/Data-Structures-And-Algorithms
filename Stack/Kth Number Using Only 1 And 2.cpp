#include<bits/stdc++.h>
using namespace std;
int main()
{
    queue<string>q;
    q.push("1");
    q.push("2");
    int k=5;
   for(int i=0;i<k;i++)
   {
       string temp=q.front();
       q.pop();
       if(i==k-1)
       {
           cout<<temp;
           break;
       }
       q.push(temp+"1");
       q.push(temp+"2");
       
   }
}
