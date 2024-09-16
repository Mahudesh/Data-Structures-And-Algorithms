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
    vector<int> rightSideView(TreeNode* root)
     {
        //Logic: In Level Order Traversal From Right To Left
        //Every First Node In The Level Is My Answer
        vector<int>ans;
        if(root==nullptr)
        return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            
            int size=q.size();
            for(int i=1;i<=size;i++)
            {
                    TreeNode* temp=q.front();
                      q.pop();
                if(i==1)
                {
                    int data=temp->val;
                      ans.push_back(data);
                }
                if(temp->right)
                q.push(temp->right);
                if(temp->left)
                q.push(temp->left);
            }
        }
        return ans;
    }
};
//Recursive Traversal
/*************************************************************
 
    Following is the Binary Tree node structure:

    template <typename T>

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void reversePreOrderTraversal(BinaryTreeNode<int>* root, vector<int>&ans, int level)
{
    if(root==nullptr)
    return;
    //If Level Equals The 1D Vector Size Then We Are Visiting That Level For The 1st Time
    if(level==ans.size())
    ans.push_back(root->data);
    if(root->right)
    reversePreOrderTraversal(root->right,ans,level+1);
    if(root->left)
    reversePreOrderTraversal(root->left,ans,level+1);
}
vector<int> printRightView(BinaryTreeNode<int>* root) 
{
    // Write your code here.
    //Recursive Way Of Traversal

    //Reverse Pre Order Traversal 
    //Root Right Left
    vector<int>ans;
    reversePreOrderTraversal(root,ans,0);
    return ans;
}
