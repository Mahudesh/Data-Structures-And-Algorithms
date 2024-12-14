#include<bits/stdc++.h>
using namespace std;
void helper(int rows, int cols, vector<pair<int,int>>& temp, vector<vector<pair<int,int>>>& ans,string& str)
{
    if(rows==0 && cols==0)
    {
        // ans.push_back(make_pair(rows,cols));
        temp.push_back(make_pair(rows,cols));
        ans.push_back(temp);
        temp.pop_back();
        
        
        cout<<str;
        cout<<endl;
        
        return;
    }
    
    if(cols<0 || rows<0)
    return;
    temp.push_back(make_pair(rows,cols));
    
    
    str.push_back('U');
    helper(rows-1,cols,temp,ans,str);
    str.pop_back();
    
    str.push_back('L');
    helper(rows,cols-1,temp,ans,str);    // ans.pop_back();
    str.pop_back();
    
    temp.pop_back();
    
    // return upWay+leftWay;
}
int main()
{
    int rows=3,cols=3;
    vector<vector<pair<int,int>>>ans;
    vector<pair<int,int>>temp;
    string str;
    helper(rows-1,cols-1,temp,ans,str);
    // for(auto it: ans)
    // {
    //     for(auto it2: it)
    //     {
    //         cout<<it2.first<<","<<it2.second<<" ";
    //     }
    //     cout<<endl;
    // }
}
