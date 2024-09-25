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
bool isValid(TreeNode* root, long long minValue, long long maxValue)
{
    if(!root)
    return true;
    //Check For Node's Value Withing The Given Range
    if(root->val>=maxValue || root->val<=minValue)
    return false;

    if(isValid(root->left,minValue,root->val) && isValid(root->right,root->val,maxValue))
    return true;
    return false;
}
    bool isValidBST(TreeNode* root) 
    {
        long long minValue=LLONG_MIN;
        long long maxValue=LLONG_MAX;
        return isValid(root,minValue,maxValue);
    }
};
