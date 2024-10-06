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
    TreeNode* reverseOddLevels(TreeNode* root) 
    {
        if(!root)
        return nullptr;
        queue<TreeNode*>q;
        q.push(root);
        int lv=0;
        // vector<int>support;
            vector<int>arr;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(lv%2!=0)
                {
                    temp->val=arr[arr.size()-1-i];
                }
                if(temp->left)
                {
                    q.push(temp->left);
                    if(lv%2==0)
                    arr.push_back(temp->left->val);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                    if(lv%2==0)
                    arr.push_back(temp->right->val);
                }
            }
            // if(lv%2==0)
            // swap(temp->left,temp->right);
            if(lv%2!=0)
            arr.clear();
            // support=arr;
            lv++;
        }
        return root;
    }
};
