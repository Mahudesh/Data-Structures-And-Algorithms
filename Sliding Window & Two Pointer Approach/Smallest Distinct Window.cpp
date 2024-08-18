int findSubString(string str)
    {
        // Your code goes here   
        int l=0,r=0;
        unordered_map<int,int>Map;
        unordered_set<int>st;
        int len=INT_MAX;
        for(auto it: str)
        st.insert(it);
        int k=st.size();
        while(r<str.length())
        {
            Map[str[r]]++;
            while(Map.size()==k)
            {
                len=min(len,r-l+1);
                Map[str[l]]--;
                if(Map[str[l]]<=0)
                Map.erase(str[l]);
                l++;
                
            }
            r++;
        }
        return len;
    }
