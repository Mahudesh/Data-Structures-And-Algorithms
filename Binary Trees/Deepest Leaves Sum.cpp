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

    int deepestLeavesSum(TreeNode* root) 
    {
       //Iterative Solution
       queue<TreeNode*>q;
       q.push(root);
    //    int lv=1;
       int sum=0;
       while(!q.empty())
       {
            int size=q.size();
             sum=0;
            for(int i=1;i<=size;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(!temp->left && !temp->right)
                sum+=temp->val;
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
            }
       }
       return sum;
    }
};
