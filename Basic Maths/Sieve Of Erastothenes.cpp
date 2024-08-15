 vector<int> sieveOfEratosthenes(int n)
    {
        // Write Your Code here
        vector<bool> ans(n+1,true);
        vector<int>res;
        // if(n<2) return 0;
        for(int i=2;i<=sqrt(n);i++)
        {
            if(ans[i])
            {
                for(int j=i*i;j<=n;j=j+i)
                {
                    ans[j]=false;
                }
            }
        }
        int cnt=0;
        for(int i=2;i<=n;i++)
        {
            if(ans[i])
            {
                res.push_back(i);
            }
        }
        return res;
    }
