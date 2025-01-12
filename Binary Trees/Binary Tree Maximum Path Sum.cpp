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

int maxPath=INT_MIN;
int helper(TreeNode* root)
{
    if(!root)
    {
        return 0;
    }

    // if(minus!=root)
    //Always Take Only The Positive Node Values Since Negative Values Reduces The Overall Path Sum
    int leftSum=max(0,helper(root->left));
    // if(minus!=root)
    int rightSum=max(0,helper(root->right));
    
    //Even If All Nodes Are Negative Values The Current Node's Value Will Be Taken Into Account
    //Current Node's Value Will Be Updated Into maxPathSum
    //Hence Everytime Atmax Current Node's Value Will Be Taken Into The Account Which Is Anyway Maximum
    //     -10
    // -20     -30

    //First It Takes -20 + 0 + 0 = -20 As MaxPath Sum
    //Next It Takes -30 + 0 + 0 =-30 Does Not Updated
    //Next It Takes -10 + 0 + 0 = -10 -20 MaxPath Sum Gets Updated
    //Atlast I Have MaxPath Sum As -10 Which Is Only One Node
    int currSum = root->val+leftSum+rightSum;
    
    maxPath=max(maxPath,currSum);
    
    // return max(leftSum,rightSum);
    return root->val+max(leftSum,rightSum);
    
    
}
    int maxPathSum(TreeNode* root)
     {
        // You are using GCC
        helper(root);
        return maxPath;

    }
};
