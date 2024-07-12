#LeetCode: 424
class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int l=0,r=0,len=0,maxFrequency=0;
        unordered_map<char,int>Map;
        //Formula For Valid Window Substring Length-MaximumFrequency <= K
        while(r<s.length())
        {
            Map[s[r]]++;
            maxFrequency=max(maxFrequency,Map[s[r]]);
            //Invalid Window Condition
            //Shrink The Left Window
            //We Can Also Use If Because They Are Asking Only Maximum Length
            //So No Point In Reducing Length Lesser Than What It Gained
            if((r-l+1) - maxFrequency >k )
            {
                //Reduce The Frequency
                Map[s[l]]--;
                l++;
            }
            //Valid Window Condition
            //Update The Maximum Length
            len=max(len,r-l+1);
            r++;
        }
        return len;
    }
};
