class Node
{
    public:
    Node* link[2];
    bool containsKey(int bit)
    {
        return link[bit]!=nullptr;
    }
    void setValue(int bit, Node* newNode)
    {
        link[bit]=newNode;
    }
    Node* getNext(int bit)
    {
        return link[bit];
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
    void insert(int num)
    {
        Node* temp=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(!temp->containsKey(bit))
            {
                temp->setValue(bit,new Node());
            }
            temp=temp->getNext(bit);
        }
    }
    int getMaximum(int num)
    {
        int maxi=0;
        Node* temp=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(temp->containsKey(1-bit))
            {
                maxi=(1<<i)|maxi;
                temp=temp->getNext(1-bit);
            }
            else
            {
                temp=temp->getNext(bit);
            }
        }
        return maxi;
    }

};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) 
    {
        Trie trie;
        for(auto it: nums)
        trie.insert(it);

        int maxi=0;
        for(auto it: nums)
        {
            maxi=max(maxi,trie.getMaximum(it));
        }
        return maxi;
        // int maxi=0;
        // for(int i=0;i<nums.size();i++)
        // {
        //     for(int j=i+1;j<nums.size();j++)
        //     {
        //         maxi=max(maxi,nums[i]^nums[j]);
        //     }
        // }
        // return maxi;
    }
};
