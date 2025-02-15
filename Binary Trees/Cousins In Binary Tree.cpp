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
void helper(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& parent, TreeNode* &first, TreeNode* &second, int x, int y)
{
    queue<TreeNode*>q;
    q.push(root);
    parent[root]=nullptr;
    while(!q.empty())
    {
        int siz=q.size();
        for(int i=0;i<siz;i++)
        {
            TreeNode* curr=q.front();
            q.pop();
            if(curr->val==x)
            first=curr;
            if(curr->val==y)
            second=curr;
            if(curr->left)
            {
                parent[curr->left]=curr;
              q.push(curr->left);
            }
            if(curr->right)
            {
                parent[curr->right]=curr;
               q.push(curr->right);
            }
        }
    }

}
    bool isCousins(TreeNode* root, int x, int y)
     {
        unordered_map<TreeNode*,TreeNode*>parent;
        TreeNode* first=nullptr;
        TreeNode* second=nullptr;
        helper(root,parent,first,second,x,y);
        // TreeNode* first=
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int siz=q.size();
              bool a=false;
              bool b=false;
            for(int i=0;i<siz;i++)
            {
                TreeNode* curr=q.front();
                q.pop();


                if(curr->val==x)
                a=true;
                if(curr->val==y)
                b=true;
                if(curr->left)
                q.push(curr->left);
                if(curr->right)
                q.push(curr->right);
            }
            if(a&&b && parent[first]!=parent[second])
            return true;
            else if(a!=b)
            return false;
        }
        return false;
    }
};
