int countSetBits(int n)
 {
    // Write your code here
    int cnt=0;
    int mod=1e9+7;
    for(int i=1;i<=n;i++)
    {
        int num=i;
        while(num>=1)
        {
            if(num&1==1)
            cnt=(cnt+1)%mod;
            num=num>>1;
        }
    }
    return cnt;
}
