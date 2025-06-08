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
void helper(TreeNode* root, int& cnt, int maxi)
{
    if(!root)
    return;
    // Track For Maximum Value In That Path
    // Dont Pass It As Reference Since Max Value Changes For Every Path
    maxi=max(maxi,root->val);
    if(root->val>=maxi)
    cnt++;
    helper(root->left,cnt,maxi);
    helper(root->right,cnt,maxi);
}
    int goodNodes(TreeNode* root)
    {
        int cnt=0;
        int maxi=INT_MIN;
        helper(root,cnt,maxi);
        return cnt;
    }
};
