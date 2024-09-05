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
int diameter=0;
// int findHeight(TreeNode* root)
// {
//     if(root==nullptr)
//     return 0;
//     int lh=findHeight(root->left);
//     int rh=findHeight(root->right);

//     return 1+max(lh,rh);
// }
// void helper(TreeNode* root)
// {

//         if(root==nullptr)
//         return ;

//         int lh=findHeight(root->left);
//         int rh=findHeight(root->right);

//          diameter=max(diameter,lh+rh);

//          diameterOfBinaryTree(root->left);
//          diameterOfBinaryTree(root->right);
// }
int findMaxHeight(TreeNode* root, int& diameter)
{
    if(root==nullptr)
    return 0;
    int lh=findMaxHeight(root->left,diameter);
    int rh=findMaxHeight(root->right,diameter);
    diameter=max(diameter,lh+rh);
    return 1+max(lh,rh);
}
    int diameterOfBinaryTree(TreeNode* root) 
    {
        //BruteForce : Find Left Height Of Each Node
        //Find Right Height Of Each Node
        //Find Sum Of Left Height And Right Height Will Give You The Longest Path
        // helper(root);
        //Optimized Way - Since FindMaximumDepth Of A Binary Tree Problem Solves
        //Height Of Each Node During Its Recursion So Find max(lh+rh) Of Diameter
        //Before Returning It's(Node's) Height(1+max(lh,rh))
        findMaxHeight(root,diameter);
        return diameter;
    }
};
