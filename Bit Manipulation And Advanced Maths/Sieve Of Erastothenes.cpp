class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {
        // Write Your Code here
        vector<bool>sieve(N+1,true);
        vector<int>arr;
        for(int i=0;i<N;i++)
        arr.push_back(i+1);
        // for(auto it: arr)
        // cout<<it<<" ";
        sieve[0]=false;
        sieve[1]=false;
        for(int i=2;i<=sqrt(N);i++)
        {
            if(sieve[i]==true)
            {
                for(int j=i*i;j<=N;j=j+i)
                {
                    sieve[j]=false;
                }
            }
        }
        vector<int>ans;
        for(int i=2;i<sieve.size();i++)
        {
            if(sieve[i]==true)
            {
                ans.push_back(arr[i-1]);
            }
        }
        return ans;
    }
};
