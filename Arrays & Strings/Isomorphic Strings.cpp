class Solution {
public:
    bool isIsomorphic(string s, string t)
     {
        //Two HashMaps
        if(s.length()!=t.length())
        return false;
        unordered_map<char,int>sMap;
        unordered_map<char,int>tMap;
        //Store The New Character Only If It Is Not Present In The Map
        for(int i=0;i<s.length();i++)
        {
            if(sMap.find(s[i])==sMap.end())
            {
                // sMap[s[ii]=
                sMap[s[i]]=i;
            }
            if(tMap.find(t[i])==tMap.end())
            {
                tMap[t[i]]=i;
            }
            //If Both Are New Character Then Both Will Have New Pair Of Indices
            //If Both Are Old Character Then  Both Should Have Old Pair Of Indices
            //If Any One Of Those Is A New Character Then One Will Have Old Indices
            //And Another Will Have New Indices
            //Then We Have Not Replaceable Pair
            //Then Return False
            //Else Return True
            if(sMap[s[i]]!=tMap[t[i]])
            return false;
        }
        return true;
    }
};
