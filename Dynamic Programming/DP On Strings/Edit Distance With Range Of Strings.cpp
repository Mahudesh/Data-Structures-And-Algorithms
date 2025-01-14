#include<bits/stdc++.h>
using namespace std;
int helper(string str1, string str2, int i, int j, vector<vector<int>> & dp)
{
    // mahu
    // su
    
    if(i==0)
    return j;
    if(j==0)
    return i;
    
    if(dp[i][j]!=-1)
    return dp[i][j];
    if(str1[i-1]==str2[j-1])
    {
        return dp[i][j]=0+helper(str1,str2,i-1,j-1,dp);
    }
    else
    {
        return dp[i][j]=min(1+helper(str1,str2,i,j-1,dp),min(1+helper(str1,str2,i-1,j,dp),1+helper(str1,str2,i-1,j-1,dp)));
    }
}
int main()
{
    vector<string>arr;
    string str;
    getline(cin,str);
    // cout<<str;
    string temp="";
    for(int i=0;i<(int)str.length();i++)
    {
        if(str[i]==' ')
        {
            arr.push_back(temp);
            temp="";
        }
        else
        {
            if(str[i]!=',')
            temp.push_back(str[i]);
        }
    }
    arr.push_back(temp);
    // for(auto it: arr)
    // cout<<it<<" ";
    string key;
    cin>>key;
    
    int mini=INT_MAX;
    int ind=0;
    for(int i=0;i<arr.size();i++)
    {
    vector<vector<int>>dp (arr[i].length()+1, vector<int>(key.length()+1,-1));
        int val=helper(arr[i],key,arr[i].length()-1,key.length()-1,dp);
        if(mini>val)
        {
            mini=val;
            ind=i;
        }
    }
    cout<<arr[ind];
    
}
