#include <bits/stdc++.h> 
bool static comp(pair<vector<int>,int>& a, pair<vector<int>,int>& b)
{
    if(a.first.back()==b.first.back())
    {
        return a.second<b.second;
    }
    return a.first.back()<b.first.back();
}
void sortTuples(vector<vector<int>>&arr)
{
    // Write your code here
    vector<pair<vector<int>,int>>tempLast;
    // sort(arr[i].begin())
    //Store The Distance As Index For The Condition of Last Element becomes Equal
    for(int i=0;i<arr.size();i++)
    {
       tempLast.push_back({arr[i],i});
    }
    sort(tempLast.begin(),tempLast.end(),comp);
    for(int i=0;i<arr.size();i++)
    {
        arr[i]=tempLast[i].first;
    }
}
