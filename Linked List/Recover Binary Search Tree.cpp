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
// void inorderTraversal(TreeNode* root,vector<int>& inorder)
// {
//     if(!root)
//     return;

//     inorderTraversal(root->left,inorder);
//     inorder.push_back(root->val);
//     inorderTraversal(root->right,inorder);
// }
// void helper(TreeNode* root, vector<int>& inorder, int& ind)
// {
//     if(!root)
//     return;

//     helper(root->left,inorder,ind);
//     root->val=inorder[ind++];
//     helper(root->right,inorder,ind);
// }
bool firstOcc=false;
bool secOcc=false;
TreeNode* prev=nullptr;
TreeNode* middle=nullptr;
TreeNode* left=nullptr;
TreeNode* right=nullptr;
void inorderTraversal(TreeNode* root)
{
    if(!root)
    return;
    inorderTraversal(root->left);
    if(prev)
    {
        if(prev->val>root->val && firstOcc==false)
        {
            firstOcc=true;
            middle=root;
            left=prev;
        }
        else if(prev->val>root->val && firstOcc==true)
        {
            secOcc=true;
            right=root;
            // return;
        }
    }
    prev=root;
    inorderTraversal(root->right);
}
    void recoverTree(TreeNode* root)
     {
        //Do Inorder Traversal And Replace All The Values According To Inorder In Existing BST
        //This Automatically Corrects The Values Of Swapped Nodes
        // vector<int>inorder;
        // inorderTraversal(root,inorder);
        // sort(inorder.begin(),inorder.end());
        // int ind=0;
        // helper(root,inorder,ind);

        //Optimized
        inorderTraversal(root);
        if(firstOcc&&secOcc)
        {
            swap(left->val,right->val);
        }
        else 
        {
            swap(left->val,middle->val);
        }
    }
};
