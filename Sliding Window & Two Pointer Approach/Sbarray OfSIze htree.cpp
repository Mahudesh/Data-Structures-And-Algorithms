class Solution {
public:
    int countGoodSubstrings(string s)
    {
        int len=s.length();
        int l=0;
        int r=0;
        unordered_map<char,int>Map;
        int cnt=0;
        int dup=1;
        while(r<len)
        {
            Map[s[r]]++;

            if(Map[s[r]]>1)
            {
                dup++;
            }
            //Either The Window Length Has Increased More Than 3
            //Or Our Window Contains Any Duplicate Letters
            //Then Shrink Our Window
            if((r-l+1>3 || dup>1) && l<=r)
                {
                    if(Map[s[l]]>1)
                    dup--;
                    Map[s[l]]--;
                    if(Map[s[l]]<=0)
                    Map.erase(s[l]);
                    l++;
                }
              if(r-l+1==3 && Map.size()==3)
                cnt++;
                r++;
        }
        return cnt;
    }
};
