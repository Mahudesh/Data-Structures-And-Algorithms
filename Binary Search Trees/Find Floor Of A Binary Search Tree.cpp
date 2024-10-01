#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void findFloor(TreeNode<int>* root, int x, int& floor)
{
    if(!root)
    return;
    if(root->val<=x)
    {
        floor=root->val;
        findFloor(root->right,x,floor);
    }
    else if(root->val>x)
    {
        findFloor(root->left,x,floor);
    }
}
int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    int floor=-1;
    findFloor(root,X,floor);
    return floor;
}
