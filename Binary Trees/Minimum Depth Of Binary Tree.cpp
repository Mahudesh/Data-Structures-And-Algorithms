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
    int minDepth(TreeNode* root) 
    {
        if(!root)
        return 0;
        if(!root->left && !root->right)
        return 1;
        queue<TreeNode*>q;
        q.push(root);
        int lv=1;
        while(!q.empty())
        {
            int siz=q.size();
            for(int i=0;i<siz;i++){
            TreeNode* curr=q.front();
            q.pop();

            if(!curr->left && !curr->right)
            return lv;
            if(curr->left)
            q.push(curr->left);
            if(curr->right)
            q.push(curr->right);
            }
            lv++;
        }
        return -1;
    }
};
