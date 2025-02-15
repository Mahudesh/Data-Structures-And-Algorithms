class Node
{
    public:
    Node* link[26];
    bool flag=false;
    void putValue(char ch, Node* newNode)
    {
        link[ch-'a']=newNode;
    }
    bool containsKey(char ch)
    {
        return link[ch-'a']!=nullptr;
    }
    Node* getNext(char ch)
    {
        return link[ch-'a'];
    }
    void setEnd()
    {
        flag=true;
    }
    bool getEnd()
    {
        return flag;
    }
};
class Trie
{
    private:
    Node* root=nullptr;
    public:
    Trie()
    {
        root=new Node();
    }
     void insert(string word)
    {
        Node* temp=root;
        for(int i=0;i<word.length();i++)
        {
            if(!temp->containsKey(word[i]))
            {
                temp->putValue(word[i],new Node());
            }
            temp=temp->getNext(word[i]);
        }
        temp->setEnd();
    }
    bool checkAllPrefixes(string& word)
    {
        Node* temp=root;
        for(int i=0;i<word.length();i++)
        {
            char ch=word[i];
            if(temp->containsKey(ch))
            {
                temp=temp->getNext(ch);
                if(temp->getEnd()==false)
                return false;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    string longestWord(vector<string>& words) 
    {
        //Fix All Words Into The Trie And Make It As A Dictionary
        Trie trie;
        for(auto it: words)
        {
            trie.insert(it);
        }
        string longest="";
        //Check For All Prefixes To Be True To Consider The String As Valid String
        for(int i=0;i<words.size();i++)
        {
            if(trie.checkAllPrefixes(words[i]))
            {
                if(longest.length()<words[i].length())
                longest=words[i];
                else if(longest.length()==words[i].length() && words[i]<longest)
                longest=words[i];
            }
        }
        return longest;

    }
};
