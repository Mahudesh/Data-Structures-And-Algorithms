class Solution {
public:
    bool checkInclusion(string s1, string s2)
     {
        unordered_map<char,int>Map;
        for(auto it: s1)
        Map[it]++;
        int l=0;
        int r=0;
        int required=0;
        //Window size is always str 1 length
        required=s1.length();
        while(r<s2.length())
        {       
            if(Map[s2[r]]>0)
            {
                required--;
            }
            Map[s2[r]]--;
            r++;

            if(required==0)
            return true;

            while(r-l==s1.length())
            {
                if(Map[s2[l]]>=0)
                {
                    required++;
                }
                Map[s2[l]]++;
                l++;
            }
        }
        return false;
    }
};
