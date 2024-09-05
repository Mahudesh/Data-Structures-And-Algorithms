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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
     {

        vector<vector<int>>ans;
        if (root == nullptr) {
            return ans;
        }

        queue<TreeNode*>q;
        q.push(root);
        //Flag used to denote the direction of traversal
        bool flag=true;
        while(!q.empty())
        {
            int size=q.size();
            vector<int>lis(size);
            for(int i=0;i<size;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                int ind;
                if(flag==true)
                {
                    //If flag is true just fill the values from starting of the array
                    // ind=i;
                    lis[i]=temp->val;
                }
                else if(flag==false)
                {
                    //If flag is false fill the values from end of the array so it gets reversed
                    // ind=size-1-i;
                    lis[lis.size()-1-i]=temp->val;
                }

                // lis[ind]=temp->val;
                if(temp->left!=nullptr)
                q.push(temp->left);
                if(temp->right!=nullptr)
                q.push(temp->right);
            }
            ans.push_back(lis);
            flag=!flag;

        }
        return ans;
    }
};
