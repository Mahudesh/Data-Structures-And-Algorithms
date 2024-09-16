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
bool isMirror(TreeNode* leftNode, TreeNode* rightNode)
{
    if(leftNode==nullptr && rightNode==nullptr)
    return true;
    if(!leftNode || !rightNode)
    return false;
    return leftNode->val==rightNode->val && isMirror(leftNode->left,rightNode->right) && isMirror(leftNode->right,rightNode->left);
}
    bool isSymmetric(TreeNode* root) 
    {
        if(root==nullptr)
        return true;
        return isMirror(root->left,root->right);
    }
};
