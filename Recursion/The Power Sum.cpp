
In a unique team-building exercise, a company has decided to distribute a certain number of resources among its departments based on mathematical powers. The company has x resources that need to be distributed such that each department receives a different power of an integer. Specifically, each department i receives n resources, where n is a given power.



George, the resource manager, needs to find all possible ways to distribute exactly x resources using the powers of integers starting from 1. Each integer's power can only be used once.



Write a program to help George determine the number of ways to distribute x resources in this manner using a recursive manner.



Example 1



Input:

10

2

Output: 

1

Explanation:

x = 10

n = 2

10 = 12 + 32, hence we have only 1 possibility.

  
#include<bits/stdc++.h>
using namespace std;
int findWays(int x, int n, int curr)
{
    if(x==0)
    return 1;
    if(x<0)
    return 0;
    if(pow(curr,n)>x)
    return 0;
    int include=findWays(x-pow(curr,n),n,curr+1);
    
    int exclude=findWays(x,n,curr+1);
    return include+exclude;
}
int main()
{
    int n;
    int x;
    cin>>x>>n;
    int curr=1;
    cout<<findWays(x,n,curr);
}
