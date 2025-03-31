class Solution {
public:
    int partitionString(string s) 
    {
        unordered_map<char,int>Map;
        int l=0;
        int r=0;
        int cnt=0;
        while(r<s.length())
        {
            if(Map.find(s[r])!=Map.end())
            {
                cnt++;
                while(l!=r)
                {
                    Map[s[l]]--;
                    if(Map[s[l]]<=0)
                    Map.erase(s[l]);
                    l++;
                }
                continue;
            }
            Map[s[r]]++;

            r++;
        }

        return cnt+1;
    }
};
