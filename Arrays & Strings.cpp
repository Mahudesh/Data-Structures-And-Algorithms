class Solution {
public:
void solve(string digits,int ind,vector<string>&ans,string& temp,unordered_map<int,string>& Map)
{
    if(ind==digits.length())
    {
        ans.push_back(temp);
        return;
    }
     int num=digits[ind]-'0';
     string str=Map[num];
     for(int i=0;i<str.length();i++)
     {
        temp.push_back(str[i]);
        solve(digits,ind+1,ans,temp,Map);
        temp.pop_back();
     }
}
    vector<string> letterCombinations(string digits)
     {
        unordered_map<int,string>Map;
        Map[2]="abc";
        Map[3]="def";
        Map[4]="ghi";
        Map[5]="jkl";
        Map[6]="mno";
        Map[7]="pqrs";
        Map[8]="tuv";
        Map[9]="wxyz";
        vector<string>ans;
        if(digits.length()==0)
        return ans;
        int ind=0;
        string temp="";
        solve(digits,ind,ans,temp,Map);
        return ans;
    }
};
