class Solution {
public:
    int longestBeautifulSubstring(string word)
    {
        int len=word.length();
        int l=0,r=0;
        int maxLen=0;
        unordered_map<char,int>Map;
        // int a=-1,e=-1,i=-1,o=-1,u=-1;
        while(r<len)
        {
            Map[word[r]]++;
            // Once You Found Order Is Wrong Then Shrink The Window
            // Its Waste Of Calculating All The Strings Before It
            if(r-1>=0 && word[r]<word[r-1])
            {
                while(l<r)
                {
                    Map[word[l]]--;
                    if(Map[word[l]]<=0)
                    Map.erase(word[l]);
                    l++;
                }
            }
            if(Map.size()==5)
            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};
