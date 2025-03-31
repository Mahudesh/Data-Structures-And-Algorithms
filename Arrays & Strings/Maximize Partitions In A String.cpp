class Solution {
  public:
    int maxPartitions(string &s) {
       
        //Look For Last Occurrence Of Each Character In The String
        //It Allows You The Maximum Right Most Boundary For A Valid Substring
        unordered_map<char,int>Map;
        for(int i=0;i<s.length();i++)
        Map[s[i]]=i;
        
        int cnt=0;
        
        int maxi=INT_MIN;
        for(int i=0;i<s.length();i++)
        {
            //If Maximum Is Reached i Such That All Characters Seen So Far Do Not Appear Later In The String
            //Allowing Us To Split The String Partition
            //Since We Already Traversed The Maximum Last Seen For Any Character In The Traversed Window
            maxi=max(maxi,Map[s[i]]);
            if(maxi==i)
            cnt++;
        }
        return cnt;
        
    }
};
