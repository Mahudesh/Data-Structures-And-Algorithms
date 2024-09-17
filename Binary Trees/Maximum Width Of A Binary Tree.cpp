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
    int widthOfBinaryTree(TreeNode* root) 
    {
        int ans=0;
        //Stores Node and index value
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            int size=q.size();
            //Before traversing each level find minimal index of every level
            //Minimal index of every level should be at the first or front element in the queue
            int min_Index=q.front().second;
            int first,last;
            for(int i=0;i<size;i++)
            {
                //Subtract the every node's index with minimal index to prevent overflow
                int curr_index=q.front().second-min_Index;
                TreeNode* temp=q.front().first;
                q.pop();
                if(i==0)
                //Meaning of first nide
                first=curr_index;
                if(i==size-1)
                //Meaning of last node
                last=curr_index;
                if(temp->left)
                {
                    //Condition for left node's index
                    q.push({temp->left,(long long)2*curr_index+1});
                }
                if(temp->right)
                {
                    //Condition for right node's index
                    q.push({temp->right,(long long)2*curr_index+2});
                }
            }
            //Calculating width which is last index - first index +1 for each level
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};
