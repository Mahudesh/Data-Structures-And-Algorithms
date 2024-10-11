class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        //Optimal Approach
        //If A Number Is A Power Of Two Then It Should Have One Bit Only
        //Do N&(N-1)==0 If IT Is A Power Of Two
        if(n<=0)
        return false;
        if((n&n-1)==0)
        return true;
        return false;
        // int f=0;
        // int c=0;
        // while(f==0)
        // {
        //     long long ans=pow(2,c);
        //     c++;
        //     if(ans>n)
        //     break;
        //     if(ans==n)
        //     {
        //        return true;
        //     }
        // }
        //     if(f==1)
        //     return true;
        //     return false;
    }
};
