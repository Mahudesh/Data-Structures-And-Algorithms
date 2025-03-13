class Solution {
public:
bool isPalindrome(string& str, int l, int r)
{
    while(l<=r)
    {
        if(str[l]!=str[r])
        return false;
        l++;
        r--;
    }
    return true;
}
void helper(string& str, int i, vector<string>& temp, vector<vector<string>>& ans)
{
    //If I Can Partition At The Last Index Then I Have All Substring Partition As Palindrome
    if(i==str.length())
    {
        ans.push_back(temp);
        return;
    }
    for(int j=i;j<=str.length()-1;j++)
    {
        if(isPalindrome(str,i,j))
        {
            //In C++, 2nd Parameter In substr() Takes The length Of The String As Parameter
            string t=str.substr(i,j-i+1);
            temp.push_back(t);
            helper(str,j+1,temp,ans);
            temp.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>>ans;
        vector<string>temp;
        helper(s,0,temp,ans);
        return ans;
    }
};
