int minimumMultiplications(vector<int>& arr, int start, int end) 
    {
        // code here
        if(start==end)
        return 0;
        queue<pair<int,int>>q;
        q.push({0,start});
        
        vector<int>dist(100000,1e9);
        dist[start]=0;
        int mod=100000;
        while(!q.empty())
        {
            auto todo=q.front();
            q.pop();
            
            int steps=todo.first;
            int nodenum=todo.second;
            
            for(auto ele : arr)
            {
                int num=(nodenum*ele)%mod;
                if(num==end)
                return steps+1;
                
                if(dist[num]>1+steps)
                {
                    dist[num]=1+steps;
                    q.push({steps+1,num});
                }
            }
        }
        return -1;
