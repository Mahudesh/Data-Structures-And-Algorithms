class Solution {
public:
bool helper(string s, int ind, int cnt)
{
    if(cnt<0)
    return false;
    if(ind==s.length())
    {
        if(cnt==0)
        return true;
        return false;
    }

    if(s[ind]=='(')
    {
       return helper(s,ind+1,cnt+1);
    }
    if(s[ind]==')')
    {
        return helper(s,ind+1,cnt-1);
    }
    //If It Is A *(Asterik)
    //Try Out All Possible Combinations
    //And If Any One Of The Combination IS True Then Return True
    return helper(s,ind+1,cnt+1)||helper(s,ind+1,cnt-1)||helper(s,ind+1,cnt);
}
    bool checkValidString(string s) 
    {
        //TC O(3^N)
        //SC O(N)
        // return helper(s,0,0);

        int min=0;
        int max=0;
        //Try To Keep The Range Of Possible Answers From Min To Max
        //For Closing Bracket Minimum And Maximum Can Be Reduced
        //For Opening Bracket Minimum And Maximum Can Be Increased
        //For Asterik Minimum Can Achieve -1 More If I Try To Use ')' At The Place Of Asterik
        //For Asterik Maximum Can Achieve +1 More If I Try TO Use '(' At The Place Of Asterik
        for(char ch: s)
        {
            if(ch=='(')
            {
                min++;
                max++;
            }
            else if(ch==')')
            {
                min--;
                max--;
            }
            else
            {
                min--;
                max++;
            }
            //If Any Time Min Goes To -1(Negative) 3rd Rule Fails (No Corresponding Left ')' For It)
            //So If Min Reaches Negative Shrink The Range From 0
            if(min<0)
            min=0;
            //Edge Case If String Starts With ')()' Then Initially Max Goes Negative
            //No '(' for ')' Hence Return False
            if(max<0)
            return false;
        }
        if(min==0)
        return true;
        return false;
    }
};
