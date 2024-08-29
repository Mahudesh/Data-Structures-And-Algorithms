#Leetcode 102
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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>>ans;
        if(root==nullptr)
        return ans;
        //Use queue data structure for tracking nodes what i need to traversal
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            //Run the loop for queue size to find how many nodes are present in a specific level
            int size=q.size();
            vector<int>lis;
            for(int i=1;i<=size;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left!=nullptr)
                q.push(temp->left);
                if(temp->right!=nullptr)
                q.push(temp->right);
                //After checking the left and right node if present or not 
                //Insert the current node value into 1d vector of that specific level
                lis.push_back(temp->val);
            }
            //Push the entire level node values into the 2d vector
            ans.push_back(lis);
        }
        return ans;
    }
};
