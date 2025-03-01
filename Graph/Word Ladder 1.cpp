class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
     {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        st.erase(beginWord);

        while(!q.empty())
        {
            auto todo=q.front();
            q.pop();
            string word=todo.first;
            int transform=todo.second;
            for(int i=0;i<word.length();i++)
            {
                char original=word[i];
                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    if(st.find(word)!=st.end())
                    {
                        //If The Word Present In Set And Also It Is The Target Word Then Return It
                        if(word==endWord)
                        return transform+1;
                        q.push({word,transform+1});
                        st.erase(word);
                    }
                }
                word[i]=original;
            }
        }
        //If There Is No Transformations Possible To Reach The Target Word Then Return 0
        return 0;
    }
};
