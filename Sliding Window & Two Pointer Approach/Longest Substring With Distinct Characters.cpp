Solution {
  public:
    int longestUniqueSubstr(string &s)
    {
        // code here
        int l=0;
        int r=0;
        int maxLen=1;
        int du=1;
        unordered_map<int,int>Map;
        while(r<s.length())
        {
            Map[s[r]]++;
            
            if(Map[s[r]]>1)
            du++;
            
            while(du>1 && l<=r)
            {
                if(Map[s[l]]>1)
                {
                    du--;
                }
                Map[s[l]]--;
                l++;
            }
            
            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
