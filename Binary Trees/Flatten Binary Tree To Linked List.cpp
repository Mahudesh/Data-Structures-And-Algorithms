/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* prevNode=nullptr;
    void flatten(TreeNode* root) 
    {
       //Do Reverse Post Order Traversal
       //Right Left Root;
       if(!root)
       return;

       flatten(root->right);
       flatten(root->left);

       root->right=prevNode;
       root->left=nullptr;

       prevNode=root;
    }
};
