class Solution
{
public:
    bool isPossible(int a,int b)
    {
        //code here
        if((a==2 || b==2) && a!=b)
        return true;
        return false;
    }
