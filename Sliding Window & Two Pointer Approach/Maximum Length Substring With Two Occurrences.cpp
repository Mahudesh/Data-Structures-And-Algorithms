class Solution {
public:
    int maximumLengthSubstring(string s)
    {
        int len=s.length();
        int l=0;
        int r=0;
        int maxLen=0;
        unordered_map<char,int>Map;
        int du=1;
        while(r<len)
        {
            Map[s[r]]++;

            if(Map[s[r]]>2)
            {
                du++;
                while(du>1 && l<=r)
                {
                    if(Map[s[l]]>2)
                    du--;
                    Map[s[l]]--;
                    l++;
                }
            }

            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;

    }
};
