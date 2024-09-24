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
    long long kthLargestLevelSum(TreeNode* root, int k) 
    {
        queue<TreeNode*>q;
        q.push(root);
        vector<long long>ans;
        long long c=0;

        while(!q.empty())
        {
            long long size=q.size();
          c++;
            long long sum=0;
            for(long long i=0;i<size;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                sum=sum+temp->val;
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
            }
            ans.push_back(sum);
        }
        if(k>c)
        return -1;
        sort(ans.begin(),ans.end());
        return ans[ans.size()-k];
    }
};
