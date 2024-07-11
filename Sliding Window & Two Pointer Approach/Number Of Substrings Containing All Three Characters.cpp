Leetcode #1358

class Solution {
public:
    int numberOfSubstrings(string s)
     {
        //Bruteforce And Better Solution
        // int cnt=0;
        // for(int i=0;i<s.length();i++)
        // {
        //     string temp="";
        //     int c=0;
        //     for(int j=i;j<s.length();j++)
        //     {
        //         temp+=s[j];
        //         if(temp.length()>=3)
        //         {
        //             if(temp.find(string(1,'a'))!= string::npos)
        //             c++;
        //             if(temp.find(string(1,'b'))!= string::npos)
        //             c++;
        //             if(temp.find(string(1,'c'))!= string::npos)
        //             c++;
        //             if(c==3)
        //             {
        //                 cnt=cnt+(s.length()-j);
        //                 break;
        //             }
        //             c=0;
        //         }
        //     }
        // }
        // return cnt;
        // // a b c a b c
        // // 0 1 2 3 4 5
        //Optimal Solution
        vector<int>abc(3,-1);
        int cnt=0;
        // b b a c b a a
        // 0 1 2 3 4 5 6
        //If I Reach 4 Then b b a c b Is A Valid Substring
        //Locate The Farthest Distance Of Any One Character Which Is A At 2
        //Then 2+1=3 Is The Answer
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='a') abc[0]=i;
            else if(s[i]=='b') abc[1]=i;
            else abc[2]=i;
            //If All The Indexes In Array Are != -1 Then It Is A Valid Window
            //We Have TO Find Minimum Window Substring That Contains All 3 Characters
            //So Find Farthest Distance Of Any 1 Character It Will Be Minimum Window Substring
            //If It Is A Valid Substring Then Every Characters Before That Farthest Distance Will Be Answer
            if(abc[0]!=-1 && abc[1]!=-1 && abc[2]!=-1)
            cnt+=min(abc[0],min(abc[1],abc[2]))+1;
        }
        return cnt;

    }
};
