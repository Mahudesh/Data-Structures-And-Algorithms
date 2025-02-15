class Trie {
public:

    struct Node
    {
        Node* link[26];
        bool flag=false;

        bool containsKey(char ch)
        {
            return link[ch-'a']!=nullptr;
        }
        void putValue(char ch, Node* newNode)
        {
            link[ch-'a']=newNode;
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
    private:
    Node* root;
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
            char ch=word[i];
            if(!temp->containsKey(ch))
            {
                temp->putValue(ch,new Node());
            }
            temp=temp->getNext(ch);
        }
        temp->setEnd();
    }
    
    bool search(string word) 
    {
        Node* temp=root;
        for(int i=0;i<word.length();i++)
        {
            if(!temp->containsKey(word[i]))
            return false;
            temp=temp->getNext(word[i]);
        }
        return temp->getEnd();
    }
    
    bool startsWith(string prefix) 
    {
        Node* temp=root;
        for(int i=0;i<prefix.length();i++)
        {
            if(!temp->containsKey(prefix[i]))
            return false;
            temp=temp->getNext(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
