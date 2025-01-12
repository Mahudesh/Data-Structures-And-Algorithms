// You are using GCC
#include<bits/stdc++.h>
using namespace std;
vector<int> kadanesAlgorithm(vector<int>&arr)
{
    int sum=0;
    int maxSum=INT_MIN;
    int tempStart=0;
    int start=0;
    int end=0;
    for(int i=0;i<arr.size();i++)
    {
        sum+=arr[i];
        // maxSum=max(maxSum,sum);
        if(maxSum<sum)
        {
            maxSum=sum;
            start=tempStart;
            end=i;
        }
        if(sum<0)
        {
            sum=0;
            tempStart=i+1;
        }
    }
    vector<int>temp(3);
    temp[0]=maxSum;
    temp[1]=start;
    temp[2]=end;
    return temp;
}
int main()
{
    int n;
    int m;
    cin>>n>>m;
    vector<vector<int>>arr(n, vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    int maxSum=INT_MIN;
    int maxLeft;
    int maxRight;
    int maxTop;
    int maxBottom;
    for(int topRow=0;topRow<n;topRow++)
    {
            vector<int>sumArray(m,0);
        for(int bottomRow=topRow;bottomRow<n;bottomRow++)
        {
            for(int col=0;col<m;col++)
            {
                sumArray[col]+=arr[bottomRow][col];
            }
            
            vector<int>temp=kadanesAlgorithm(sumArray);
            int sum=temp[0];
            int left=temp[1];
            int right=temp[2];
            if(maxSum<sum)
            {
                maxSum=sum;
                maxLeft=left;
                maxRight=right;
                maxTop=topRow;
                maxBottom=bottomRow;
                
            }
        }
    }
    
    // if(maxSum<)
    cout<<"from row "<<maxTop<<" to "<<"row "<<maxBottom<<endl;
    cout<<"from col "<<maxLeft<<" to "<<"col "<<maxRight<<endl;
    cout<<maxSum;
}
