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
TreeNode* constructBinaryTree(vector<int>&inorder, int inStart, int inEnd, vector<int>&postorder, int postStart, int postEnd, map<int,int>&Map)
{
    if(inStart>inEnd || postStart>postEnd)
    return nullptr;

    TreeNode* root=new TreeNode(postorder[postEnd]);

    int inRootInd=Map[root->val];
    int xelementsleft=inRootInd-inStart;

    root->left=constructBinaryTree(inorder,inStart,inRootInd-1,postorder,postStart,postStart+xelementsleft-1,Map);
    root->right=constructBinaryTree(inorder,inRootInd+1,inEnd,postorder,postStart+xelementsleft,postEnd-1,Map);
    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        map<int,int>Map;
        for(int i=0;i<inorder.size();i++)
        {
            Map[inorder[i]]=i;
        }
        int inStart=0;
        int inEnd=inorder.size()-1;
        int postStart=0;
        int postEnd=postorder.size()-1;
        TreeNode* root=constructBinaryTree(inorder,inStart,inEnd,postorder,postStart,postEnd,Map);
        return root;
    }
};
