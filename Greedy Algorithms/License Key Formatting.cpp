class Solution {
public:
    string licenseKeyFormatting(string str, int k)
     {

    //Greedy Approach
    //By Traversing From Right To Left And Concatenating Dashes For Every K Group
    //Finally First Group Will Have Lesser Than Or Equal To Characters In It
    string temp="";
    for(int i=0;i<str.length();i++)
    {
        if(isalnum(str[i]))
        {
            // temp+=(toupper(str[i]));
            temp.push_back(toupper(str[i]));
        }
    }
    int val=k;
    string ans="";
    for(int i=temp.length()-1;i>=0;i--)
    {
        if(val==0)
        {
            val=k;
            // ans=ans+'-';
            ans.push_back('-');
        }
        // ans=ans+temp[i];
        ans.push_back(temp[i]);
        val--;
    }
    reverse(ans.begin(),ans.end());
    return ans;

    }
};
