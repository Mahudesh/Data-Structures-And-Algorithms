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
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        //Stores Vertical And Horizontal Axis Values With Node For Traversal
        queue<pair<TreeNode*,pair<int,int>>>q;
        //Stores A Particular Nodes Vertical, (Vertical's Levels and Multiple Data)
        //Uses Multiset To Store The Duplicated Values Also But In Sorted Order
        //Each Vertical May Contain Many Levels and In Each Level Can Have Many Nodes
        //So In Map First int Denotes Verticals (For Example: 0)
        //In Map Second int,multiset<int> Denotes The Vertical's Levels And Its Multiple Notes
        map<int,map<int,multiset<int>>>Map;

        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto todo=q.front();
            q.pop();
            TreeNode* temp=todo.first;
            int vertical=todo.second.first;
            int level=todo.second.second;
            Map[vertical][level].insert(temp->val);
            if(temp->left)
            {
                q.push({temp->left,{vertical-1,level+1}});
            }
            if(temp->right)
            {
                q.push({temp->right,{vertical+1,level+1}});
            }
        }
        vector<vector<int>>ans;
        for(auto p : Map)
        {
                vector<int>col;
            for(auto pair: p.second)
            {
                for(auto ele : pair.second)
                {
                    col.push_back(ele);
                }
            
            }
            ans.push_back(col);
        }
        return ans;

    }
};
