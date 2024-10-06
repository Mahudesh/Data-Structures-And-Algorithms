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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) 
    {
        if(!root)
        return nullptr;
        if(depth==1)
        {
            TreeNode* newRoot=new TreeNode(val);
            newRoot->left=root;
            newRoot->right=nullptr;
            root=newRoot;
            return root;
        }
        queue<TreeNode*>q;
        q.push(root);
        int d=2;
        while(!q.empty())
        {
            int size=q.size();
            if(d==depth)
            {
                for(int i=1;i<=size;i++)
                {
                    TreeNode* temp=q.front();
                    q.pop();
                     TreeNode* l=new TreeNode(val);
                     TreeNode* r=new TreeNode(val);

                     if(temp->left)
                     {
                        l->left=temp->left;
                     }
                        temp->left=l;
                     if(temp->right)
                     {
                        r->right=temp->right;
                     }
                      temp->right=r;

                    
                }
                
                break;
            }
            else
            {
                
                    for(int i=1;i<=size;i++)
                    {
                        TreeNode* temp=q.front();
                        q.pop();
                        if(temp->left)
                        q.push(temp->left);
                        if(temp->right)
                        q.push(temp->right);
                    }
                
            }
            d++;
        }
        return root;
    }
};
