/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void findParentNodes(TreeNode* root, map<TreeNode*, TreeNode*>&Map)
{
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* temp=q.front();
        q.pop();
        if(temp->left)
        {
            Map[temp->left]=temp;
            q.push(temp->left);
        }
        if(temp->right)
        {
            Map[temp->right]=temp;
            q.push(temp->right);
        }
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        vector<int>ans;
        if(!root)
        return ans;
        map<TreeNode*,TreeNode*>parent_track;
        findParentNodes(root,parent_track);
        map<TreeNode*,bool>visitedMap;
        //To Start From Target Node
        queue<TreeNode*>q;
        q.push(target);
        visitedMap[target]=true;
        int dist=0;
        while(!q.empty())
        {
            int size=q.size();
            //If Maximum Distance Of K Gets Reached By Doing Radially Outward Direction At Every Level
            //Then Do Break
            if(dist==k)
            break;
            for(int i=0;i<size;i++)
            {
                TreeNode* currNode=q.front();
                q.pop();
                //Check For Parent Node Exists
                if(parent_track[currNode] && !visitedMap[parent_track[currNode]])
                {
                    q.push(parent_track[currNode]);
                    //If So We Gonna Traverse That Node Too So Make That Node As Visited
                    visitedMap[parent_track[currNode]]=true;
                }
                //Check For Left Node Exists
                if(currNode->left!=nullptr && !visitedMap[currNode->left])
                {
                    q.push(currNode->left);
                    //If So We Gonna Traverse That Node Too So Make That Node As Visited
                    visitedMap[currNode->left]=true;
                }
                //Check For Right Node Exists
                if(currNode->right!=nullptr && !visitedMap[currNode->right])
                {
                    q.push(currNode->right);
                    //If So We Gonna Traverse That Node Too So Make That Node As Visited
                    visitedMap[currNode->right]=true;
                }
            }
            dist++;
        }
        //The Elements Remaining In Queue Will Be The Answer
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            ans.push_back(temp->val);
        }
        return ans;
    }
};
