class Node
{
    public:
    Node* link[2];
    bool containsKey(int bit)
    {
        return link[bit]!=nullptr;
    }
    void putValue(int bit, Node* newNode)
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
                temp->putValue(bit,new Node());
            }
            temp=temp->getNext(bit);
        }
    }
    int getMaximum(int num)
    {
        Node* temp=root;
        int maxi=0;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(temp->containsKey((1-bit))){
            maxi=maxi|(1<<i);
            temp=temp->getNext(1-bit);
            }
            else
            temp=temp->getNext(bit);
        }
        return maxi;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries)
     {
        Trie trie;
        sort(nums.begin(),nums.end());
        vector<pair<int,pair<int,int>>>offq;
        for(int i=0;i<queries.size();i++)
        {
            offq.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(offq.begin(),offq.end());
        vector<int>ans(queries.size(),0);
        int ind=0;
        for(int i=0;i<offq.size();i++)
        {
            int ai=offq[i].first;
            int xi=offq[i].second.first;
            int qind=offq[i].second.second;

            while(ind<nums.size() && nums[ind]<=ai)
            {
                trie.insert(nums[ind]);
                ind++;
            }
            if(ind!=0){
            int maxi=trie.getMaximum(xi);
            ans[qind]=maxi;
            }
            else
            ans[qind]=-1;

        }
        return ans;
    }
};
