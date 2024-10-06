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
int sum=0;
void helper(TreeNode* root)
{
    if(!root)
    return;
    //Sum Of Left Leaf Nodes
    //If There Exists A Node At Left Then Check Its Both Left And Right Are Nullptr To Be A LeafNode
    //root->left->left will check its left side nullptr
    //root->left->right will check its right side nullptr
    if(root->left && root->left->left==nullptr && root->left->right==nullptr)
    sum+=root->left->val;
    helper(root->left);
    helper(root->right);
}
    int sumOfLeftLeaves(TreeNode* root) 
    {
        helper(root);
        return sum;
    }
};
