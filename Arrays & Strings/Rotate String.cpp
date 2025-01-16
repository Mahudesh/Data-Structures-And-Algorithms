class Solution {
public:
    bool rotateString(string s, string goal)
     {
        // for(int i=0;i<s.length();i++)
        // {
        //     string left=s.substr(0,i+1);
        //     string right=s.substr(i+1,s.length()-i+1);

        //     if(right+left == goal)
        //     return true;
        // }
        // return false;
        //Optimized Version

        if(s.length()!=goal.length())
        return false;

        //Since String Is Rotated Then If I Multiply The String By X2 I Can Get The Rotated String In It
        s=s+s;
        if(s.find(goal)!= string :: npos)
        return true;
        return false;
    }
  
};
