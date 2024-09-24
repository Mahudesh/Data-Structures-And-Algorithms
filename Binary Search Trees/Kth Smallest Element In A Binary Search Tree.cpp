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
void inorderTraversal(TreeNode* root, int k, int& cnt, int& KthSmallest)
{
    if(!root)
    return;
    inorderTraversal(root->left,k,cnt,KthSmallest);
    cnt=cnt+1;
    if(cnt==k)
    {
        KthSmallest=root->val;
        return;
    }
    inorderTraversal(root->right,k,cnt,KthSmallest);
}
    int kthSmallest(TreeNode* root, int k) 
    {
        //Always Do Inorder Traversal Of BST Which Will Always Give You The Sorted Order
        int cnt=0,KthSmallest=root->val;
        inorderTraversal(root,k,cnt,KthSmallest);
        return KthSmallest;
    }
};
