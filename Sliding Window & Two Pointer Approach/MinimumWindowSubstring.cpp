        class Solution {
        public:
            string minWindow(string s, string t) 
            {
                unordered_map<int,int>Map;
                for(auto it: t)
                Map[it]++;
                int l=0;
                int r=0;
                int cnt=0;
                int index=-1;
                int minlen=INT_MAX;

                while(r<s.length())
                {
                    if(Map[s[r]]>0)
                    {
                        cnt++;
                    }
                    Map[s[r]]--;

                    while(cnt==t.length())
                    {
                        if(r-l+1 < minlen)
                        {
                            minlen=r-l+1;
                            index=l;
                        }

                        Map[s[l]]++;
                        if(Map[s[l]]>0)
                        {
                            cnt--;
                        }
                        l++;
                    }
                    r++;
                }
                return index==-1?"":s.substr(index,minlen);
            }
        };
