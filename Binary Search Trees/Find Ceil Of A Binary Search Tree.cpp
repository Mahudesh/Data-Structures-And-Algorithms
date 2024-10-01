#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/
void findCeil(BinaryTreeNode<int>* root, int x, int& ceil)
{
    if(!root)
    return;
    if(root->data>=x)
    {
        ceil=root->data;
        findCeil(root->left,x,ceil);
    }
    else
    {
        findCeil(root->right,x,ceil);
    }
}
int findCeil(BinaryTreeNode<int> *node, int x)
{
    // Write your code here.
    int ceil=-1;
    findCeil(node,x,ceil);
    return ceil;
}
