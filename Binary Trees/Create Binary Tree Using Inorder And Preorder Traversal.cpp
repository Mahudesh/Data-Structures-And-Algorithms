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
TreeNode* constructTree(vector<int>&preorder,int preStart, int preEnd, vector<int>&inorder,int inStart, int inEnd,map<int,int>&Map)
{
    if(preStart>preEnd || inStart>inEnd)
    return nullptr;

    TreeNode* root=new TreeNode(preorder[preStart]);
    int inRootInd=Map[root->val];
    int xelementsleft=inRootInd-inStart;

    root->left=constructTree(preorder,preStart+1,preStart+xelementsleft,inorder,inStart,inRootInd-1,Map);
    root->right=constructTree(preorder,preStart+xelementsleft+1,preEnd,inorder,inRootInd+1,inEnd,Map);

    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
     {
        map<int,int>Map;
        for(int i=0;i<inorder.size();i++)
        {
            Map[inorder[i]]=i;
        }
        int preStart=0;
        int preEnd=preorder.size()-1;
        int inStart=0;
        int inEnd=inorder.size()-1;
        TreeNode* root=constructTree(preorder,preStart,preEnd,inorder,inStart,inEnd,Map);
        return root;
    }
};
