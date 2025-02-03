Solution {
  public:
    // Function to find the height of a binary tree.
    int height(Node* node)
    {
        if(!node)
        return -1;
        // code here
        int lh=height(node->left);
        int rh=height(node->right);
        
        return 1+max(lh,rh);
    }
};
