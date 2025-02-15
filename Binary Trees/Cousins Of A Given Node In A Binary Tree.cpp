#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void helper(BinaryTreeNode<int>* root, unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& Map, BinaryTreeNode<int>* &first, int node)
{
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    Map[root]=nullptr;
    while(!q.empty())
    {
        int siz=q.size();
        for(int i=1;i<=siz;i++)
        {
            BinaryTreeNode<int>* curr=q.front();
            q.pop();

            if(curr->data==node)
            first=curr;
            if(curr->left){
                Map[curr->left]=curr;
            q.push(curr->left);
            }
            if(curr->right){
                Map[curr->right]=curr;
            q.push(curr->right);
            }
        }
    }
}
vector<int> cousinsOfNode(BinaryTreeNode<int> *root, int node)
{
    //  Write your code here.
    unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>Map;
    BinaryTreeNode<int> * first=nullptr;
    helper(root,Map,first,node);
    vector<int>ans;
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    while(!q.empty())
    {
        int siz=q.size();
        bool yes=false;
        for(int i=1;i<=siz;i++)
        {
            BinaryTreeNode<int> *curr=q.front();
            q.pop();

            if(curr->left)
            {
                if(curr->left->data==node)
                yes=true;
                q.push(curr->left);
            }
            if(curr->right)
            {
                if(curr->right->data==node)
                yes=true;
                q.push(curr->right);
            }
        }
        if(yes==true)
        {
            while(!q.empty())
            {
                BinaryTreeNode<int> * temp=q.front();
                q.pop();
                if(Map[temp]!=Map[first])
                ans.push_back(temp->data);
            }
            break;
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
