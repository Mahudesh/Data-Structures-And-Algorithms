class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    int findHeight(Node* root)
    {
        if(!root)
        return 0;
        int lh=findHeight(root->left);
        int rh=findHeight(root->right);
        
        return 1+max(lh,rh);
    }
    bool isBalanced(Node *root)
    {
        //  Your Code here
        if(!root)
        return true;
        int lh=findHeight(root->left);
        int rh=findHeight(root->right);
        if(abs(lh-rh)>1)
        return false;
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        
        if(left==false|| right==false)
        return false;
        return true;
    }
};
