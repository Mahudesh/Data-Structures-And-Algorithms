#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>arr={4,2,7,5,9,8,1,3};
    for(int i=1;i<arr.size();i++)
    {
        int j=i-1;
        while(j>=0)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                j--;
            }
            else
            break;
        }
    }
    for(auto it: arr)
    cout<<it<<" ";
} //23 1 5 6 7
  // 1 23 5 6 7
