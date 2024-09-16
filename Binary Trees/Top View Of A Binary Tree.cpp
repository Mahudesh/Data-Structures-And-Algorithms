/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root)
{
    // Write your code here.
    //Use Vertical Line Axis Method

    //In this Top View I dont Require Horizontal Levels
    //Since The First Node Of Every Vertical Axis Is My Answer
    //So Queue Stores Node With Vertical Axis Values
    //Map Stores Unique Vertical Axis Has First Node Gets Stored
    queue<pair<TreeNode<int>*,int>>q;
    map<int,int>Map;

    q.push({root,0});
    while(!q.empty())
    {
        auto todo=q.front();
        q.pop();
        TreeNode<int>* temp=todo.first;
        int vertical=todo.second;

        if(Map.find(vertical)==Map.end())
        {
            Map[vertical]=temp->data;
        }

        if(temp->left)
        {
            q.push({temp->left,vertical-1});
        }
        if(temp->right)
        {
            q.push({temp->right,vertical+1});
        }
    }
    vector<int>ans;
    for(auto pair: Map)
    {
        ans.push_back(pair.second);
    }
    return ans;
}
