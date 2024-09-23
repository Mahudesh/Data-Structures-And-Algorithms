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

    TreeNode* insertIntoBST(TreeNode* root, int val)
     {
        //Recursive Approach
        // if(!root)
        // {
        //     return new TreeNode(val);
        // }
        // if(val<root->val)
        // {
        //     root->left=insertIntoBST(root->left,val);
        // }
        // else if(val>root->val)
        // {
        //     root->right=insertIntoBST(root->right,val);
        // }
        // return root;

        //Iterative Approach

        if(!root)
        {
            return new TreeNode(val);
        }
        TreeNode* temp=root;
        while(true)
        {
            if(val>temp->val)
            {
                if(temp->right!=nullptr)
                {
                    temp=temp->right;
                }
                else
                {
                    temp->right=new TreeNode(val);
                    break;
                }
            }
            else
            {
                if(temp->left!=nullptr)
                {
                    temp=temp->left;
                }
                else
                {
                    temp->left=new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};
