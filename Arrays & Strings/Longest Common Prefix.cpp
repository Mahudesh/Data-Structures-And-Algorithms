#include<bits/stdc++.h>
string longestCommonPrefix(vector<string> &arr, int n)
{
    //Sort The Strings Via Alphabetical Order
    //So When U Take First And Last String
    //You Will Surely Get The Maximum Matched Prefix Characters Between All Strings
    //If A Character Is In The Last String Then It Is Bound To Be In 0 To n-2 String Also
    //Since It Is Sorted
    sort(arr.begin(),arr.end());
    string first=arr[0];
    string last=arr[n-1];
    string ans="";
    int i=0,j=0;
    while(i<first.length() && j<last.length())
    {
        if(first[i]==last[j])
        {
            ans.push_back(first[i]);
            i++;
            j++;
        }
        else
        break;
    }
    return ans;
}


