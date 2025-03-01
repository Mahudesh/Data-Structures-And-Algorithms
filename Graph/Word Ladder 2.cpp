vector<vector<string>> findSequences(string beginWord, string targetWord, vector<string>& wordList) 
    {
        // code here
        vector<vector<string>>ans;
        
        queue<vector<string>>q;
        q.push({beginWord});
        
        unordered_set<string>st(wordList.begin(),wordList.end());
        
        vector<string>lastUsedOnLevel;
        lastUsedOnLevel.push_back(beginWord);
        int lv=0;
        while(!q.empty())
        {
            vector<string>seq=q.front();
            q.pop();
            
            if(lv<seq.size())
            {
                lv++;
                //erase all the words
                //that has been used in previous levels to transform
                for(string lastUsed : lastUsedOnLevel)
                st.erase(lastUsed);
               lastUsedOnLevel.clear();
            }
            
            //store the answers
            if(seq.back()==targetWord)
            {
                //the first sequence where we reach the end
                if(ans.size()==0)
                ans.push_back(seq);
                else if(ans[0].size()==seq.size())
                ans.push_back(seq);
            }
            string word=seq.back();
            
        
            for(int i=0;i<word.length();i++)
            {
                char original=word[i];
                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    if(st.find(word)!=st.end())
                    {
                        seq.push_back(word);
                        q.push(seq);
                        lastUsedOnLevel.push_back(word);
                        seq.pop_back();
                    }
                    word[i]=original;
                }
            }
        }
        return ans;
    }
