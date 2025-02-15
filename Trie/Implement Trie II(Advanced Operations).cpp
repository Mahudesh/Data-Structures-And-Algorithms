#include <bits/stdc++.h> 
class Trie
{
    public:
    class Node
    {
        public:
        Node* link[26];
        int currPrefix=0;
        int endsWith=0;

        bool containsKey(char ch)
        {
            return link[ch-'a']!=nullptr;
        }
        Node* getNext(char ch)
        {
            return link[ch-'a'];
        }
        void putValue(char ch, Node* newNode)
        {
            link[ch-'a']=newNode;
        }
        void IncrementEndsWith()
        {
            endsWith++;
        }
        void IncrementPrefix()
        {
            currPrefix++;
        }
        int getEndsWith()
        {
            return endsWith;
        }
        int getPrefixCount()
        {
            return currPrefix;
        }
        void reduceEndsWithCount()
        {
            endsWith--;
        }
        void reducePrefixCount()
        {
            currPrefix--;
        }
    };
    private:
    Node* root=nullptr;
    public:

    Trie()
    {
        // Write your code here.
        root=new Node();
    }

    void insert(string &word)
    {
        // Write your code here.
        Node* temp=root;
        for(int i=0;i<word.length();i++)
        {
            char ch=word[i];
            if(!temp->containsKey(ch))
            {
                temp->putValue(ch,new Node());
            }
            temp=temp->getNext(ch);
            temp->IncrementPrefix();
        }
        temp->IncrementEndsWith();
    }

    int countWordsEqualTo(string &word)
    {
        // Write your code here.
        Node* temp=root;
        for(int i=0;i<word.length();i++)
        {
            char ch=word[i];
            if(temp->containsKey(ch))
            {
                temp=temp->getNext(ch);
            }
            else
            {
                return 0;
            }

        }
        return temp->getEndsWith();
    }

    int countWordsStartingWith(string &word)
    {
        // Write your code here.
        Node* temp=root;
        for(int i=0;i<word.length();i++)
        {
            char ch=word[i];
            if(temp->containsKey(ch))
            {
                temp=temp->getNext(ch);
            }
            else
            {
                return 0;
            }
        }
        return temp->getPrefixCount();
    }

    void erase(string &word)
    {
        // Write your code here.
        Node* temp=root;
        for(int i=0;i<word.length();i++)
        {
            char ch=word[i];
            if(temp->containsKey(ch))
            {
                temp=temp->getNext(ch);
                temp->reducePrefixCount();
            }
            else
            {
                return;
            }
        }
        temp->reduceEndsWithCount();
    }
};
