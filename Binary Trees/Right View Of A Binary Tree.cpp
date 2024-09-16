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
    vector<int> rightSideView(TreeNode* root)
     {
        //Logic: In Level Order Traversal From Right To Left
        //Every First Node In The Level Is My Answer
        vector<int>ans;
        if(root==nullptr)
        return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            
            int size=q.size();
            for(int i=1;i<=size;i++)
            {
                    TreeNode* temp=q.front();
                      q.pop();
                if(i==1)
                {
                    int data=temp->val;
                      ans.push_back(data);
                }
                if(temp->right)
                q.push(temp->right);
                if(temp->left)
                q.push(temp->left);
            }
        }
        return ans;
    }
};
