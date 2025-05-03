#include <bits/stdc++.h> 
bool isPalindrome(string& s, int l, int r)
{
    while(l<r)
    {
        if(s[l]!=s[r])
        return false;

        l++;
        r--;
    }
    return true;
}
void helper(string& s, int ind, vector<string>& temp, vector<vector<string>>& ans)
{
    if(ind==s.length())
    {
        ans.push_back(temp);
        return;
    }
    for(int j=ind;j<s.length();j++)
    {
        if(isPalindrome(s,ind,j))
        {
            string str=s.substr(ind,j-ind+1);
            temp.push_back(str);
            helper(s,j+1,temp,ans);
            temp.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<vector<string>>ans;
    vector<string>temp;
    helper(s,0,temp,ans);
    return ans;
}
