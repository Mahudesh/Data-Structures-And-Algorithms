#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

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
int cnt=0;
int ans=0;
bool helper(BinaryTreeNode<int>* root, int targetNodeVal, int k)
{
    if(!root)
    return false;

    //If It Is The Target Node Then Return True
    if(root->data==targetNodeVal)
    return true;
    if(helper(root->left,targetNodeVal,k) || helper(root->right,targetNodeVal,k))
    {
        //If Any Of The Above Condition Return True Current Node Is The Ancestor Of That Node
        cnt++;
        //Wait For Untill The Kth Ancestor Node
        if(cnt==k)
        ans=root->data;
        return true;
    }
    return false;
}
int findKthAncestor(BinaryTreeNode<int> *root, int targetNodeVal, int k) 
{
    // Write your code here.
    cnt=0;
    ans=-1;
    helper(root,targetNodeVal,k);
    return ans;

}
