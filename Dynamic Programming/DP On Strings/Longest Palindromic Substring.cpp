class Solution {
public:
// bool isPalindrome(string str, int l, int r)
// {
//     while(l<=r)
//     {
//         if(str[l]!=str[r])
//         return false;
//         else
//         {
//             l++;
//             r--;
//         }
//     }
//     return true;
// }
    string longestPalindrome(string s) 
    {
        // string ans="";
        // int maxLen=0;
        // for(int i=0;i<s.length();i++)
        // {
        //     string temp="";

        //     for(int j=i;j<s.length();j++)
        //     {
        //         temp.push_back(s[j]);
        //         if(isPalindrome(s,i,j))
        //         {
        //             if(maxLen<j-i+1)
        //             {
        //                 maxLen=j-i+1;
        //                 ans=temp;
        //             }
        //         }
        //     }
        // }
        // return ans;

        if(s.length()==1)
        return s;
        string LPS="";
        for(int i=1;i<s.length();i++)
        {
            //For Odd Length Palindrome
            int low=i;
            int high=i;
            while(s[low]==s[high])
            {
                low--;
                high++;
                if(low==-1 || high==s.length())
                break;
            }
            string temp=s.substr(low+1,high-low-1);
            if(temp.length()>LPS.length())
            {
                LPS=temp;
            }

            //For Even Length Palidnrome

            low=i-1;
            high=i;
            while(s[low]==s[high])
            {
                low--;
                high++;

                if(low==-1 || high==s.length())
                break;
            }
            temp=s.substr(low+1,high-low-1);
            if(temp.length()>LPS.length())
            {
                LPS=temp;
            }

        }
        return LPS;
    }
};
