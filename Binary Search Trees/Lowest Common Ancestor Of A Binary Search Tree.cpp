/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
     {
        // if(!root || root==q || root==p)
        // return root;
        // TreeNode* leftSearch=lowestCommonAncestor(root->left,p,q);
        // TreeNode* rightSearch=lowestCommonAncestor(root->right,p,q);

        // if(leftSearch==nullptr)
        // return rightSearch;
        // else if(rightSearch==nullptr)
        // return leftSearch;
        // else
        // return root;
        //If Root Is Nullptr Then Return Nullptr
        if(!root)
        return nullptr;
        //If Anyone Of The Data Matches After Traversing With Both Values On Right Or Left
        if(root->val==p->val || root->val==q->val)
        return root;
        //If Both Values Are Smaller Than Current Node Then Move Left
        if(p->val<root->val && q->val<root->val)
        {
            return lowestCommonAncestor(root->left,p,q);
        }
        //If Both  Values Are Greater Than Current Node Then Move Right
        else if(p->val>root->val && q->val>root->val)
        {
            return lowestCommonAncestor(root->right,p,q);
        }
        //Once Direction Of One Node Is On Left And Another Node Is On Right
        //If It Splits then For Sure It (Current Root) Should Be The Answer
        else
        {
            return root;
        }
    }
};
