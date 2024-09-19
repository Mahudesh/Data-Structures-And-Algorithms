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
TreeNode* findParentMap(TreeNode* root, int target,map<TreeNode*,TreeNode*>&Map)
{
    queue<TreeNode*>q;
    q.push(root);
    TreeNode* node;
    while(!q.empty())
    {
        TreeNode* temp=q.front();
        q.pop();
        if(temp->val==target)
        node=temp;

        if(temp->left)
        {
            q.push(temp->left);
            Map[temp->left]=temp;
        }
        if(temp->right)
        {
            q.push(temp->right);
            Map[temp->right]=temp;
        }
    }
    return node;
}
    int amountOfTime(TreeNode* root, int start) 
    {
        map<TreeNode*,TreeNode*>parent_Map;
        TreeNode* target=findParentMap(root,start,parent_Map);
        int timer=0;
        map<TreeNode*,bool>visitedMap;
        queue<TreeNode*>q;
        q.push(target);
        visitedMap[target]=true;
        while(!q.empty())
        {
            int size=q.size();
            int flag=0;
            for(int i=0;i<size;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                //If It Has Any One Node (Parent Or Left Or Right) And It Is Not Visited
                //Then It Will Burn All These Three Completely At One Second
                //So Increase Overall One Second If Any One Node(Parent Or Left Or Right) Is Burnt
                if(parent_Map[temp] && !visitedMap[parent_Map[temp]])
                {
                    flag=1;
                    visitedMap[parent_Map[temp]]=true;
                    q.push(parent_Map[temp]);
                }
                if(temp->left && !visitedMap[temp->left])
                {
                    flag=1;
                    visitedMap[temp->left]=true;
                    q.push(temp->left);
                }
                if(temp->right && !visitedMap[temp->right])
                {
                    flag=1;
                    visitedMap[temp->right]=true;
                    q.push(temp->right);
                }
            }
            if(flag==1)
            timer++;
        }
        return timer;
    }
};
