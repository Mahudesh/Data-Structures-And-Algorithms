 public:
    // Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string str1, string str2) 
    {

        // Your code here
        unordered_map<char,int>Map;
        for(auto it: str1)
        Map[it]++;
        for(auto it: str2)
        Map[it]--;
        for(auto it: Map)
        {
            if(it.second!=0)
            return false;
        }
        return true;
    }
