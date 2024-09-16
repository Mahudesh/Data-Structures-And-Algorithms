#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>arr={4,2,7,5,9,8,1,3};
    int j;
    for(int i=0;i<arr.size()-1;i++)
    {
        int minIndex=i;
        for( j=i+1;j<arr.size();j++)
        {
            if(arr[j]<arr[minIndex])
            {
                minIndex=j;
            }
        }
        swap(arr[minIndex],arr[i]);
    }
    for(auto it: arr)
    cout<<it<<" ";
}
