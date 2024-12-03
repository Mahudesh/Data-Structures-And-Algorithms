// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cin>>arr[i][j];
    }
    vector<int>known(n,0);
    vector<int>knownby(n,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==1)
            {
                knownby[j]++;
                known[i]++;
            }
        }
    }
    int cnt=0;
    int ind=0;
    for(int i=0;i<n;i++)
    {
        if(knownby[i]>known[i])
        {
            cnt++;
            if(cnt==1)
            ind=i;
            if(cnt>1)
            break;
        }
    }
    if(cnt==1)
    cout<<"Influential Individual: "<<ind;
    else
    cout<<"There is no influential individual in the group";
}
