class Solution {
public:
    int divide(int dividend, int divisor)
     {

        if(dividend==divisor)
        return 1;
        long n=abs(dividend);
        long d=abs(divisor);
        bool sign=true;
        if(dividend>=0 && divisor<0)
        sign=false;
        else if(dividend<=0 && divisor>0)
        sign=false;
        long c=0;
        long ans=0;
        while(n>=d)
        {
             c=0;
            while(c<31 && n>=(d<<(c+1)))
            {
                c++;
            }
            ans=ans+(1<<c);
            n-=(d<<c);
        }
        if(ans==(1<<31)&& sign==true)
        return INT_MAX;
        if(ans==(1<<31)&& sign==false)
        return INT_MIN;
        return sign?ans: -ans;
    }
};
