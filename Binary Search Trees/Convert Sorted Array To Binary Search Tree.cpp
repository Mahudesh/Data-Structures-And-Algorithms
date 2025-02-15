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
TreeNode* helper(vector<int>& nums, int inStart, int inEnd)
{   
    if(inStart>inEnd)
    return nullptr;
    int mid=(inStart+inEnd)/2;
    TreeNode* root=new TreeNode(nums[mid]);
    root->left=helper(nums,inStart,mid-1);
    root->right=helper(nums,mid+1,inEnd);
    return root;
}
    TreeNode* sortedArrayToBST(vector<int>& nums)
     {
        if(nums.size()==0)
        return nullptr;
        if(nums.size()==1)
        return new TreeNode(nums[0]);

        int inStart=0;
        int inEnd=nums.size()-1;
        return helper(nums,inStart,inEnd);
    }
};
