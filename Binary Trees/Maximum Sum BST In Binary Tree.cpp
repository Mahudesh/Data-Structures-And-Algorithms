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
 class Demo
 {
    public:
    int maxSum;
    int maxVal;
    int minVal;
    Demo(int maxSum, int maxVal, int minVal)
    {
        this->maxSum=maxSum;
        this->maxVal=maxVal;
        this->minVal=minVal;
    }
 };
class Solution {
public:
int maxi=0;
    Demo helper(TreeNode* root)
    {
        if(!root)
        return Demo(0,INT_MIN,INT_MAX);

        auto left=helper(root->left);
        auto right=helper(root->right);

        if(left.maxVal<root->val && root->val<right.minVal)
        {
            maxi=max(maxi,root->val+left.maxSum+right.maxSum);
            return Demo(root->val+left.maxSum+right.maxSum,max(root->val,right.maxVal),min(root->val,left.minVal));
        }
        else
        {
            return Demo(max(left.maxSum,right.maxSum),INT_MAX,INT_MIN);
        }
    }

    int maxSumBST(TreeNode* root) 
    {
        if(!root)
        return 0;
        
        helper(root).maxSum;
         return maxi;

    }
};
