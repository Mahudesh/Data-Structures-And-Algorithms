#include<bits/stdc++.h>
using namespace std;
int main()
{
    queue<string>q;
    q.push("11");
    q.push("22");
    int k=5;
   for(int i=1;i<=k;i++)
   {
       string temp=q.front();
       q.pop();
       if(i==k)
       {
           cout<<temp;
           break;
       }
       int n=temp.length();
       string first=temp.substr(0,n/2);
       string second=temp.substr(n/2,n);
       q.push(first+"11"+second);
       q.push(first+"22"+second);
       
   }
}
