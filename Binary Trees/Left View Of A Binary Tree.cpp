#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void preOrderTraversl(TreeNode<int>* root, vector<int>&ans, int level)
{
    if(root==nullptr)
    return;
    if(level==ans.size())
    ans.push_back(root->data);
    //Dont Pass Level As Reference Since For Each Recursion Dream The Level Value Has To be Maintained

    preOrderTraversl(root->left,ans,level+1);
    preOrderTraversl(root->right,ans,level+1);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    //Recursive Approach
    vector<int>ans;
    preOrderTraversl(root,ans,0);
    return ans;
}
