class Solution
{
    public:
   bool p=false;
   bool s=false;
    void findSuccessor(Node* root, int key, Node*& suc)
    {
        if(!root)
        return;
        if(root->key>key)
        {
            suc=root;
            // s=!s;
            s=true;
            findSuccessor(root->left,key,suc);
        }
        else
        {
            findSuccessor(root->right,key,suc);
        }
    }
    void findPredecessor(Node* root, int key, Node*& pre)
    {
        if(!root)
        return;
        if(root->key<key)
        {
            p=true;
            pre=root;
            findPredecessor(root->right,key,pre);
        }
        else 
        {
            findPredecessor(root->left,key,pre);
        }
    }
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        findSuccessor(root,key,suc);
        findPredecessor(root,key,pre);
        if(!p)
        pre=nullptr;
         if(!s)
        suc=nullptr;

        
    }
