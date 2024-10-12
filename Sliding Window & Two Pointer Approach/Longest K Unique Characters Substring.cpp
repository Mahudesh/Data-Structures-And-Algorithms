class Solution{
  public:
    int longestKSubstr(string s, int k) 
    {
    // your code here
    unordered_map<char,int>Map;
    int l=0;
    int r=0;
    int maxLen=INT_MIN;
    if(k<0)
    return -1;
    while(r<s.length())
    {
        Map[s[r]]++;
        
        if(Map.size()==k)
        maxLen=max(maxLen,r-l+1);
        
        while(Map.size()>k)
        {
            Map[s[l]]--;
            if(Map[s[l]]<=0)
            Map.erase(s[l]);
            l++;
        }
        r++;
    }
    if(maxLen==INT_MIN)
    return -1;
    return maxLen;
    }
