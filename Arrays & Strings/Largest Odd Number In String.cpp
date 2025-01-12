class Solution {
public:
    string largestOddNumber(string num)
     {
        // int r=num.length()-1;
        // string ans="";
        int len=-1;
        bool f=false;
        for(int i=num.length()-1;i>=0;i--)
        {
            int ch=num[i]-'0';
            if(ch!=0 && ch % 2 !=0)
            {
                f=true;
                len=i+1;
                break;
            }
        }
        if(!f)
        return "";
        return num.substr(0,len);
    }
};
