lass Solution{
    public:
     bool flag;
    void postOrder(Node* root)
    {
        if(!root)
        return;
        
        postOrder(root->left);
        postOrder(root->right);
        
        if(!root->left && !root->right)
        return;
        int tot=0;
        if(root->left)
        {
            tot=tot+root->left->data;
        }
        if(root->right)
        {
            tot=tot+root->right->data;
        }
        if(tot!=root->data)
        {
            flag=false;
        }
    }
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     // Add your code here
     flag=true;
     postOrder(root);
     if(!flag)
     return 0;
     return 1;
    }
